//
// Created by pawel on 12.01.2018.
//

#ifndef NET_SIMULATION_RECEIVERPREFERENCES_H
#define NET_SIMULATION_RECEIVERPREFERENCES_H

class ReceiverPreferences {
    class ReceiverPreference {
    private:
        std::map<IPackageReceiver*, double> probabilities;
    public:
        std::map<IPackageReceiver*, double> getPreferences();
        void setPreferences(std::map<IPackageReceiver*, double>);
        void addReceiver(IPackageReceiver*);
        void addReceiverWithProbability(IPackageReceiver*, double);
        void removeReceiver(IPackageReceiver*);
        IPackageReceiver* drawReceiver(double);
        std::pair<IPackageReceiver*, double>* view();
    }; // ReceiverPreferences
};


#endif //NET_SIMULATION_RECEIVERPREFERENCES_H
