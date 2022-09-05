#ifndef Entity_h
#define Entity_h

#include <string>

namespace envlibcpp {

    // @author Daniel McCoy Stephenson
    // @since August 26th, 2022
    class Entity {
        public:
            Entity(int id, std::string entityName);
            int getId();
            std::string getName();
            int getEnvironmentId();
            int getGridId();
            std::string getLocationId();
            void setName(std::string newName);
            void setEnvironmentId(int id);
            void setGridId(int id);
            void setLocationId(std::string id);
            void resetLocationId();
            envlibcpp::Entity& getEntity(int entityId);
        private:
            int id;
            std::string name;
            int environmentId;
            int gridId;
            std::string locationId;
    };
}

#endif