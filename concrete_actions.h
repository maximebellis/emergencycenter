#ifndef CONCRETE_ACTIONS_H
#define CONCRETE_ACTIONS_H

#include "action.h"
#include <iostream>

//Scenario 1 actions
class ActivatingBuildingAlarm : public Action {
public:
    void execute() const override {
        std::cout << "Activating the building alarm..." << std::endl;
    }
};

class SendMessageToKULeuvenDispatch : public Action {
public:
    void execute() const override {
        std::cout << "Sending message to KULeuven central dispatch..." << std::endl;
    }
};

class ActivatingRoomAlarm : public Action {
public:
    void execute() const override {
        std::cout << "Activating the room alarm..." << std::endl;
    }
};

class SendEmailToLore : public Action {
public:
    void execute() const override {
        std::cout << "Sending an email to lore.hennebel@kuleuven.be..." << std::endl;
    }
};

// Actions for Lab Electronics (10.01) and (10.02)
class SendSMSToGert : public Action {
public:
    void execute() const override {
        std::cout << "Sending SMS to Gert Vanloock..." << std::endl;
    }
};

// Actions for Alma Kitchen (1.03)
class ActivateExtinctionSystem : public Action {
public:
    void execute() const override {
        std::cout << "Activating the automatic extinction system..." << std::endl;
    }
};

class SendMessageToAlarmDispatch : public Action {
public:
    void execute() const override {
        std::cout << "Sending message to Alarm dispatch..." << std::endl;
    }
};

class ActivateLocalAlarm : public Action {
public:
    void execute() const override {
        std::cout << "Activating local alarm..." << std::endl;
    }
};

class WarnPolice : public Action {
public:
    void execute() const override {
        std::cout << "Warning the police..." << std::endl;
    }
};

class WarnKULeuvenSecurity : public Action {
public:
    void execute() const override {
        std::cout << "Warning KULeuven security..." << std::endl;
    }
};


//Scenario 2 actions
// John Shed
class ActivatingHouseAlarm : public Action {
public:
    void execute() const override {
        std::cout << "Activating the house alarm..." << std::endl;
    }
};

class SendMessageToFireDept : public Action {
public:
    void execute() const override {
        std::cout << "Sending message to Fire department of the neighborhood..." << std::endl;
    }
};

class ActivateLight : public Action {
public:
    void execute() const override {
        std::cout << "Activating the light..." << std::endl;
    }
};

class ActivateAirConditioner : public Action {
public:
    void execute() const override {
        std::cout << "Turning on the air conditioner..." << std::endl;
    }
};

// Vicky Kitchen
class SendEmailToVicky : public Action {
public:
    void execute() const override {
        std::cout << "Sending an email to vicky.cooke@gmail.com..." << std::endl;
    }
};

// Dave Living Room
class ActivateSprinklerSystem : public Action {
public:
    void execute() const override {
        std::cout << "Activating the sprinkler system..." << std::endl;
    }
};

// Kaitlin Lab
class ActivateAllAlarmsInNeighborhood : public Action {
public:
    void execute() const override {
        std::cout << "Activating all alarms in the neighborhood..." << std::endl;
    }
};

class SendEmailToKaitlin : public Action {
public:
    void execute() const override {
        std::cout << "Sending an email (motion detected during Kaitlin's sleep time)..." << std::endl;
    }
};
// Scenario 3 actions

class WarnPeacekeepingForce : public Action {
public:
    void execute() const override {
        std::cout << "Warning Zorglax peacekeeping force (police)..." << std::endl;
    }
};

class SoundAlarmAndSendMessage : public Action {
public:
    void execute() const override {
        std::cout << "Sounding an alarm and sending an electronic message..." << std::endl;
    }
};

class ActivateMagmaCoolingSprinklers : public Action {
public:
    void execute() const override {
        std::cout << "Activating magma-cooling sprinklers..." << std::endl;
    }
};
class WarnScientists : public Action {
public:
    void execute() const override {
        std::cout << "Warning the scientists..." << std::endl;
    }
};

class ActivateMotionAlarm : public Action {
public:
    void execute() const override {
        std::cout << "Activating motion alarm..." << std::endl;
    }
};

class AlertFireFighters : public Action {
public:
    void execute() const override {
        std::cout << "Alerting the fire fighters..." << std::endl;
    }
};


#endif // CONCRETE_ACTIONS_H
