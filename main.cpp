#include <iostream>
#include "Component System/SparseSet.h"
#include <vector>
#include <unordered_set>
//goal create a vector that can hold any type of vector using templates
/*

//the family is used to create in place unique identifiers for component systems
class TypeManager
{
    static std::size_t identifier() {
        static std::size_t value = 0;
        return value++;
    }
public:
    template<typename>
    static std::size_t type()
    {
        static const std::size_t value = identifier();
        return value;
    }
};


struct VectorShit
{
   template<typename T>
    static void addVector()
    {
       int position = type<T>();
       while(vectorOfVectors.size() <= position)
       {
           void* var = nullptr;
           vectorOfVectors.push_back(var);
       }

       static std::vector<T> var = std::vector<T>();

       vectorOfVectors[position] = &var;
    }
    template<typename T>
    inline static  std::vector<T>* getVector()
    {
        int position = type<T>();
        if(vectorOfVectors.size() <= position)
        {
            addVector<T>();
        }
        void* returnVal = vectorOfVectors[position];
        std::vector<T>* var2 = static_cast<std::vector<T>*>(returnVal);
        return var2;
    }
    template<typename T>
    inline static  T getVectorItem(int x)
    {
        int position = type<T>();
        if(vectorOfVectors.size() <= position)
        {
            addVector<T>();
        }
        void* returnVal = vectorOfVectors[position];
        std::vector<T>* var2 = static_cast<std::vector<T>*>(returnVal);
        return (*var2)[x];
    }

private:
    static inline std::vector<void*> vectorOfVectors;
    static std::size_t identifier() {
        static std::size_t value = 0;
        return value++;
    }
    template<typename>
    static std::size_t type()
    {
        static const std::size_t value = identifier();
        return value;
    }

};
class GayClassShit
{
public:
    int x;
    int y;
};

template<int x =0>
struct VectorV
{
    inline static int X;
};

struct vectorManager
{
public:
    static inline int RefCount = 0;
    static std::size_t identifier() {
        static std::size_t value = 0;
        return value++;
    }
    template<int N>
    static std::size_t type()
    {
        static const std::size_t value = identifier();
        return value;
    }
};

template <int n>
struct meta
{
    inline static int var;
};
template<>
struct meta<0>
{
    static int stuff()
    {

    }
};

struct VectorOFV
{
    template<typename T>
    static std::vector<T>& getVector()
    {
        static std::vector<T> var = std::vector<T>();
        return var;
    }
};
void printFunction(int position)
{
   auto v=  VectorOFV::getVector<int>();
   std::cout<<v[position]<<std::endl;
}
*/

struct color{
    int r;
    int g;
    int b;
};
struct mesh {
    std::vector<std::vector<int>> positions;
};

void ReadMesh(const mesh& shape)
{
    std::cout<<"Begin \n";
    for(auto iter1 : shape.positions)
    {
        std::cout<<"[ ";
        for (auto iter2 : iter1)
        {
            std::cout<<" ";
            std::cout<<iter2<<" ";
        }
        std::cout<<" ]"<<std::endl;
    }
}
int main() {
    std::cout << "Hello, World!" << std::endl;
/*
    VectorShit::addVector<int>();
    std::vector<int>*  myInt = VectorShit::getVector<int>();
    myInt->push_back(6);
    myInt->push_back(7);
    auto myShittyVector = VectorShit::getVector<GayClassShit>();
    GayClassShit SomeGayAssVariable{2,3};
    myShittyVector->push_back(SomeGayAssVariable);
    std::vector<int>*  myInt2 = VectorShit::getVector<int>();
    std::cout<<VectorShit::getVectorItem<GayClassShit>(0).x<<std::endl;


    int i = vectorManager::type<1>();
    int j = vectorManager::type<2>();
    std::cout<<i<<std::endl;
    std::cout<<j<<std::endl;
    int typeStuff = 6;
    int moreTypeStuff =7;

    auto vectorStuff = VectorOFV::getVector<int>();
    vectorStuff.push_back(5);
    vectorStuff.push_back(7);
    vectorStuff.push_back(12);
    printFunction(1);
    */
    mesh MeshID{{{1,2,3},{3,4,5}}};
    mesh MeshID2 {{{3,6,9},{3,4,5}}};
    mesh MeshID3 {{{3,6,9},{12,15,18}}};
    SparseSet<mesh> SparseMesh;
    SparseMesh.addComponent(1,MeshID);
    SparseMesh.addComponent(4, MeshID2);
    SparseMesh.addComponent(5, MeshID3);


    return 0;
}
