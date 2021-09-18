#include <algorithm>
#include <cmath>
#include <functional>
#include <numeric>
#include <vector>


double ArithmeticAverage(const std::vector<int > & a, const std::vector<int > &b)
{
    if(a.empty() && b.empty()){
        return 0;
    }
    if(a.size() == b.size())
    {
        return static_cast<double>( std::inner_product(a.begin(),
                                                    a.end(), 
                                                    b.begin(), 
                                                    0, 
                                                    std::plus<>(),
                                                    std::plus<>())
                )/ ( a.size() + b.size() );
    }
    else 
    {
        return static_cast<double>(std::accumulate(a.begin(),
                                                   a.end(),
                                                   std::accumulate(b.begin(), b.end(),0))
                ) / ( a.size() + b.size() );
    }
        
}


double Distance(const std::vector<int >& a, const std::vector<int >& b)
{
    if(a.empty() && b.empty()){
        return 0;
    }
    auto squareDifference = [](const auto & lhs , const auto & rhs)
                            {return pow( (lhs - rhs), 2 ); };
    auto result = [&squareDifference](auto & first, auto & second)
                  {return std::sqrt(static_cast<double>(std::inner_product(first.begin(),
                                                                first.end(), 
                                                                second.begin(), 
                                                                0, 
                                                                std::plus<>(),
                                                                squareDifference ) ) );};
    int sizeDiff = a.size() - b.size();
    if( sizeDiff )
    {
        if( sizeDiff < 0 ){
            std::vector<int > aa{a};
            aa.insert(aa.end(), abs(sizeDiff),0);
            return result(aa,b);
        }
        else{
            std::vector<int > bb{b};
            bb.insert(bb.end(), abs(sizeDiff),0);
            return result(a,bb);
        }
    }
    else
    {
        return result(a,b);
    }

}

