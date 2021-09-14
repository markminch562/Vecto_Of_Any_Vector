//
// Created by Mark Minch  on 9/13/21.
//

#ifndef SPARSESET_H
#define SPARSESET_H
#include <iostream>
#include <vector>
#include <queue>

//allow the number to reach 65535 entitys on the screen
typedef uint16_t Entity;
template<typename T>
class SparseSet
{
    //to make things super fast we have a double index for out dense set

    //The Entity Index takes the position of a component in the dense set and uses it to look up the
    //the number of the entity the component belongs too
    std::vector<Entity> EntityIndex;

    //The Component Index is the inverse of the Entity Index
    //It takes an Entity's number and gives you back the Entity
    std::vector<uint32_t> ComponentIndex = std::vector<uint32_t>(100,-1);

    //the dense set is Dense so at no time people are putting in or getting out data should there
    //be any holes, if something is removed from the middle or front move an item from the front to the back
    std::vector<T> DenseSet;
public:
    //Adds a Component to your Entity
    bool addComponent(Entity entt, T component)
    {
        //too many enttity so you cant add another to the system
        if(entt >= ComponentIndex.size())
        {
            return false;
        }
        int position = DenseSet.size();
        DenseSet.push_back(component);
        EntityIndex.push_back(entt);
        ComponentIndex[entt] = position;

    }

    inline T GetComponent(Entity entt)
    {
        return DenseSet[ComponentIndex[entt]];
    }
    //removes the compoenent from the Entity
    inline bool deleteComponent(Entity entt)
    {
        //find where the component is located in the dense set
        int position = ComponentIndex[entt];
        if(position == -1)
        {
            //there was no component associated with that entity
            return false;
        }
        int size = DenseSet.size() -1;
        if(position == size)
        {
            //the component is on the back of the set
            DenseSet.pop_back();
            EntityIndex.pop_back();
            ComponentIndex[entt] = -1;

        }
        else
        {
            //move the item in the back to the current index and update the set
            DenseSet[position] = DenseSet[size];
            EntityIndex[position] = EntityIndex[size];
            ComponentIndex[entt] = ComponentIndex[EntityIndex[size]];
            DenseSet.pop_back();
            EntityIndex.pop_back();
        }
        return true;
    }
    //returns an index of Entities that currently have a component
    inline std::vector<Entity> getEntities()
    {
        return EntityIndex;
    }
    inline std::vector<Entity> getComponents()
    {
        return DenseSet;
    }
};


#endif //SPARSESET_H
