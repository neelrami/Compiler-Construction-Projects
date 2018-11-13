#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <stdexcept>

using namespace std;

vector <string> type;
vector <string> keyword;
vector <string> type_var;
vector <string> type_func;
vector <string> var;
vector <string> func;

int check_type(string a)
{
    for(int i=0;i<type.size();i++)
    {
        if(type[i]==a)
            return 1;
    }
    return 0;
}

int check_keyword(string a)
{
    for(int i=0;i<keyword.size();i++)
    {
        if(keyword[i]==a)
            return 1;
    }
    return 0;
}

int check_func_exists(string f)
{
    for(int i=0;i<func.size();i++)
    {
        if(func[i]==f)
            return 1;
    }
    return 0;
}

int check_var_exists(string v)
{
    for(int i=0;i<var.size();i++)
    {
        if(var[i]==v)
            return 1;
    }
    return 0;
}

int check_num(string a)
{
    int c=0;
    for(int i=0;i<a.size();i++)
    {
        int m=int(a.at(i));
        if((m>=65&&m<=90)||(m>=97&&m<=122))
            c++;
    }

    if(c==a.size()-1)
        return 1;
    else
        return 0;
}

int main()
{
    ifstream file;
    file.open("scan.txt");
    char c;

    type.push_back("int");
    type.push_back("float");

    type.push_back("double");

    type.push_back("string");

    type.push_back("char");

    type.push_back("void");

    type.push_back("long");
    keyword.push_back("case");
    keyword.push_back("switch");
    keyword.push_back("for");
    keyword.push_back("while");
    keyword.push_back("break");
    keyword.push_back("if");
    keyword.push_back("return");
    string temp;
    string a;
    string data_temp;
    if (file.is_open())
    {
        while (!file.eof())
        {
            getline(file,temp);
            //cout<<temp<<endl;
            if(temp.find("//")!=0)
            {
                for(int i=0;i<temp.size();i++)
                {
                    c=temp.at(i);

                    if(c!=' ' && c!='(' && c!=',' && c!=';' && c!='=' && c!=')')
                    {
                        if(c!='{' &&c!='}' && c!='\n' && c!='\t')
                            a=a+c;
                    }
                    else
                    {
                        if(check_num(a)==1)
                        {
                            a="";
                        }
                        else if(c==' ')
                        {
                            if(check_keyword(a)!=1)
                                data_temp=a;
                            a="";
                        }
                        else if(c==',')
                        {
                            type_var.push_back(data_temp);
                            var.push_back(a);
                            a="";
                        }
                        else if(c==';')
                        {
                            if(check_var_exists(a)!=1)
                            {
                                type_var.push_back(data_temp);
                                var.push_back(a);
                            }
                            a="";
                            data_temp="";
                            break;
                        }
                        else if(c=='=')
                        {
                            if(check_var_exists(a)!=1)
                            {
                                type_var.push_back(data_temp);
                                var.push_back(a);
                            }
                            a="";
                            if(temp.find(',')>temp.size())
                            {
                                data_temp="";
                                break;
                            }
                            else
                            {
                                for(int j=i;j<temp.size();j++)
                                {
                                    if(temp.at(j)==',')
                                    {
                                    //cout<<"j"<<j<<endl;
                                        i=j;
                                        break;
                                    }
                                }
                            }
                        }
                        else if(c=='(')
                        {
                            if(check_keyword(a)!=1&&check_func_exists(a)!=1)
                            {
                                type_func.push_back(data_temp);
                                func.push_back(a);
                            }
                            a="";
                            data_temp="";
                            break;
                        }
                    }
                }
            }
            temp="";
        }
    }
    cout<<"Functions\n";
    for(int i=0;i<func.size();i++)
    {
        cout<<"Return Type = "<<type_func[i]<<" "<<"Function Name = "<<func[i]<<endl;
    }

    cout<<endl;
    cout<<"Variables\n";
    for(int i=0;i<var.size();i++)
    {
        cout<<"Variable Type = "<<type_var[i]<<" "<<"Variable Name = "<<var[i]<<endl;
    }
    return 0;
}
