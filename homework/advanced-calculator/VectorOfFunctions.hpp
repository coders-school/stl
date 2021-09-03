#include <vector>

#include "advancedCalculator.hpp"
class SomeClass()
{
    public:
        void add(void (*function)()) {
	{
    vectoroffunctions.push_back(function);
}
	}
        void invoke_all() {
	
	}
    private:
        std::vector<void ()()> functions_;
}
SomeClass::addThingy(void (*function)())
{
    vectoroffunctions.push_back(&function);
}
SomeClass::actionWithDiffrentOutcomes()
{
    (*vectoroffunctions[0])();;
}
