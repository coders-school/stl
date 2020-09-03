#pragma once

//class advance_calculator?
/*  
    main loop (taking input from user)
    all commands in map ( key[+] and command), value should be std::function<> which is wrapper for lambdas
    application should return errorcode  when user enters bad data
    

*/
class ErrorCode;

ErrorCode process(std::string input, double* out);
