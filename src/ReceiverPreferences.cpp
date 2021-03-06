//
// Created by pawel on 12.01.2018.
//

#include <random>
#include "../include/ReceiverPreferences.h"

void redistributeProbabilityUniformly(std::map<IPackageReceiver*, double> &probabilities) {
    for (auto & iterator : probabilities) {
        iterator.second = 1.0/probabilities.size();
    }
};

void redistributeProbabilityProportionally (std::map<IPackageReceiver*, double> &probabilities, double prob = 0) {
    double total = 0.0;
    for (const auto & iterator : probabilities) {
        total += iterator.second;
    }
    if (total <= 0) {
        redistributeProbabilityUniformly(probabilities);
    }
    else {
        double proportion = (1.0-prob)/total;
        for (auto & iterator : probabilities) {
            iterator.second *= proportion;
        }
    }
};

IPackageReceiver* ReceiverPreferences::drawReceiver() {
    if(probabilities.empty())
        return nullptr;

    std::vector <double> val;
    std::vector <IPackageReceiver*> key;

    for (const auto &m : probabilities) {
        val.push_back(m.second);
        key.push_back(m.first);
    }
    std::discrete_distribution<int> d(val.begin(), val.end());

    return key[d(gen)];
}

/*
void ReceiverPreferences::addReceiver(IPackageReceiver* newReceiver) {
    probabilities[newReceiver] = 0.2;
    redistributeProbabilityProportionally(probabilities);
}
*/

std::vector<std::pair<IPackageReceiver *, double>> ReceiverPreferences::view() const {
    std::vector<std::pair<IPackageReceiver *, double>> pairs;

    for(const auto & p : probabilities) {
        pairs.emplace_back(p);
    }
    return pairs;
}

void ReceiverPreferences::removeReceiver(IPackageReceiver * receiver) {
    probabilities.erase(receiver);
    redistributeProbabilityProportionally(probabilities);
}

bool isProper(const std::map<IPackageReceiver*, double> &probabilities) {
    double sum = 0.0;
    for (const auto & iterator : probabilities) {
        if (iterator.second < 0 || iterator.second > 1)
            return false;
        sum += iterator.second;
    }

    return sum <= 1.0;
};

void ReceiverPreferences::setPreferences(const std::map<IPackageReceiver *, double> & newProbabilities) {
    if(isProper(newProbabilities))
        probabilities = newProbabilities;
}

void ReceiverPreferences::addReceiver(IPackageReceiver * newReceiver, double prob) {
    if (prob > 0.0 || prob <= 1.0) {
        if (!probabilities.empty()){
            redistributeProbabilityProportionally(probabilities, prob);
            probabilities[newReceiver] = prob;
        } else {
            probabilities[newReceiver] = 1.0;
        }

    } else {
        probabilities[newReceiver] = prob;
        redistributeProbabilityUniformly(probabilities);
    }
}

bool ReceiverPreferences::hasEmptyConnection() const {
	for(const auto & iterator : probabilities)
	{
		if(iterator.first == nullptr)
            return true;
	}
	return false;
}
