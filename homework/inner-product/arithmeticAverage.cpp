#include <cmath>
#include <numeric>
#include <functional>

double ArithmeticAverage(std::vector<int> vec1, std::vector<int> vec2) {
		
    	return inner_product(vec1.begin(), vec1.end(),
        		     vec2.begin(), 
			     0.0, 
		             std::plus<>{},
			     [&](const auto& lhs, const auto& rhs) ->double {return (lhs + rhs) / (2.0 * vec1.size());}
    			     );

}


long double Distance(std::vector<int> vec1, std::vector<int> vec2) {
	return std::sqrt(inner_product(vec1.begin(), vec1.end(),
                             	       vec2.begin(),
                             	       0.0,
                             	       std::plus<>{},
                             	       [&](const auto& lhs, const auto& rhs) ->double {return std::pow(rhs-lhs, 2.0);}));		
}

