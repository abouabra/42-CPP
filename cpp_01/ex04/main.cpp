#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>

int main(int ac,char **av)
{
    if(ac != 4)
    {
        std::cout << "please enter two arguments" << std::endl;
        return 1;
    }

    std::fstream file1;
    std::fstream file2;
    std::string name(av[1]);
    std::string S1(av[2]);
    std::string S2(av[3]);
    std::string text;
    std::string tmp;
    std::string result;
    
    name.append(".replace");
    file1.open(av[1], std::ios::in);
    file2.open(name, std::ios::out);

    if(!file1 || !file2)
    {
        std::cout << "Error Occurred during Opening files" << std::endl;
        return 1;
    }

    while(getline(file1, tmp))
    {
        text.append(tmp);
        if(file1.eof())
            break;
        text.append("\n");
    }
    size_t start = 0;
    size_t find = text.find(S1, start);
    while(find != std::string::npos)
    {
        result.append(text,start,find - start);
        result.append(S2);
        start = find + S1.length();
        find = text.find(S1, start);
    }
    result.append(text,start,text.length() - start);


    file2 << result;
    
    file1.close();
    file2.close();
    return 0;
}