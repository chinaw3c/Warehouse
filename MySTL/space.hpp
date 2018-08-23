/*************************************************************************
	> File Name: space.hpp
	> Author: 刘傲天
	> Mail: 1151172004@qq.com
	> Created Time: Wed 22 Aug 2018 08:44:30 PM CST
 ************************************************************************/
#include <string>

/*delspace清除多余的空格*/
std::string delspace(std::string& data){
    if (data.find("  ") == std::string::npos){
        return data;
    }
    return delspace(data.replace(data.find("  "), 2, " "));
}
