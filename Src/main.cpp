#include <iostream>
#include "EntityUpdate.pb.h"

using namespace AM;

void fillEntity(pb::Entity* entity) {
    entity->set_id(1000);
    entity->set_x(426.123);
    entity->set_y(92034.1238);
    entity->set_z(8234.1920);
    entity->set_velx(426.123);
    entity->set_vely(92034.1238);
    entity->set_velz(8234.1920);

    const unsigned int numInputs = 6;
    for (unsigned int i = 0; i < numInputs; ++i) {
        entity->add_inputstates(pb::Entity::InputState::Entity_InputState_Pressed);
    }
}

int main() {
    // Run all entity counts that we want size benchmarks for.
    const std::vector<unsigned int> numEntitiesPerRun = {0, 1, 2, 3, 5, 10, 100, 1000};
    for (unsigned int numEntities : numEntitiesPerRun) {
        std::cout << "For " << numEntities << " entities:" << std::endl;

        // Build the message.
        pb::EntityUpdate entityUpdate;

        for (unsigned int i = 0; i < numEntities; ++i) {
            fillEntity(entityUpdate.add_entities());
        }

        // Double check that the reported size is the same as the string size.
        std::string messageString = "";
        entityUpdate.SerializeToString(&messageString);
        if (messageString.length() != entityUpdate.ByteSizeLong()) {
            std::cout << "Reported size didn't equal string size." << std::endl;
        }

        // Print the size.
        std::cout << "Message size: " << entityUpdate.ByteSizeLong() << std::endl;
    }

    return 0;
}

