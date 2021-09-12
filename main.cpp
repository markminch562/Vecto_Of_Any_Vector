#include <iostream>
#include <vector>
//goal create a vector that can hold any type of vector using templates


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

int main() {
    std::cout << "Hello, World!" << std::endl;

    VectorShit::addVector<int>();
    std::vector<int>*  myInt = VectorShit::getVector<int>();
    myInt->push_back(6);
    myInt->push_back(7);
    auto myShittyVector = VectorShit::getVector<GayClassShit>();
    GayClassShit SomeGayAssVariable{2,3};
    myShittyVector->push_back(SomeGayAssVariable);
    std::vector<int>*  myInt2 = VectorShit::getVector<int>();
    std::cout<<VectorShit::getVectorItem<GayClassShit>(0).x<<std::endl;

    return 0;
}
