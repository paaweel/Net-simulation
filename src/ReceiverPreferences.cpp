//
// Created by pawel on 12.01.2018.
//

#include <random>
#include "../include/ReceiverPreferences.h"


IPackageReceiver* ReceiverPreferences::drawReceiver() {
    std::vector <double> val;
    std::vector <IPackageReceiver*> key;
    for (auto m : probabilities) {
        val.push_back(m.second);
        key.push_back(m.first);
    }
    std::discrete_distribution<int> d(val.begin(), val.end());

    return key[d(gen)];
}

void ReceiverPreferences::addReceiver(IPackageReceiver*  newReceiver) {
    probabilities[newReceiver] = 0;
    for (auto & iterator : probabilities) {
        iterator.second = 1.0/probabilities.size();
    }
}

ReceiverPreferences::ReceiverPreferences() {
    std::random_device rd;
    std::mt19937 _gen(rd);
    gen = _gen;
}

std::vector<std::pair<IPackageReceiver *, double>> ReceiverPreferences::view() {
    std::vector<std::pair<IPackageReceiver *, double>> pairs;

    for(const auto & p : probabilities) {
        pairs.emplace_back(p);
    }
    return pairs;
}

void ReceiverPreferences::removeReceiver(IPackageReceiver * receiver) {
    probabilities.erase(receiver);
    for (auto & iterator : probabilities) {
        iterator.second = 1.0/probabilities.size();
    }
}
