#include <iostream>
#include <cctype>
#include <string>
int s1;
int s2;
int s3;
int s4;
int s5;
int s6;
int coddcod();
int dnv(){
    char dv;
    std::cout<<"One more time?[y/n]"<<std::endl;
    std::cin>>dv;
    if(tolower(dv) == 's' || tolower(dv) == 'y'){
        coddcod();
    }
    return 0;
}
int coddcod(){
    int g1 = 0;
    int g2 = 0;
    int g3 = 0;
    int g4 = 0;
    

    std::cout<<"Write your phrase"<<std::endl;
    std::string in;
    std::cin.ignore();
    std::getline(std::cin, in);

    int rt1[26] = {9, 0, 2, 3, 5, 1, 4, 6, 12, 7, 15, 19, 13, 18, 24, 8, 10, 11, 14, 16, 20, 17, 22, 21, 25, 23};
    int iv1[26];
    int rt2[26] = {8, 3, 0, 2, 10, 12, 19, 15, 11, 14, 13, 18, 16, 20, 22, 4, 17, 1, 5, 21, 25, 6, 23, 7, 9, 24};
    int iv2[26];
    int rt3[26] = {25, 0, 24, 1, 23, 2, 22, 3, 21, 4, 20, 5, 19, 6, 18, 7, 17, 8, 16, 9, 15, 10, 14, 11, 13, 12};
    int iv3[26];
    int rt4[26] = {0, 10, 20, 1, 11, 21, 2, 12, 22, 3, 13, 23, 4, 14, 24, 5, 15, 25, 6, 16, 7, 17, 8, 18, 9, 19};
    int iv4[26];
    int rlf[26] = {5, 3, 4, 1, 2, 0, 14, 10, 9, 8, 7, 15, 20, 16, 6, 11, 13, 25, 22, 21, 12, 19, 18, 24, 23, 17};
    for(int i = 0; i <= 25; i++){
        iv1[rt1[i]] = i;
        iv2[rt2[i]] = i;
        iv3[rt3[i]] = i;
        iv4[rt4[i]] = i;
    }
    std::string cd;
    int sv = 0;
    for(char l : in){
        if(!isalpha(l)){
            cd += l;
        }
        else{
        if(sv >= 6){
            sv = 0;
        }
        int ns[6] = {s1, s2, s3, s4, s5, s6};
        g1 += ns[sv];
        if(g1 >= 26){
            g1 -= 26;
            g2 += ns[sv];
            if(g2 >= 26){
                g2 -= 26;
                g3 += ns[sv];
                if(g3 >= 26){
                    g3 -= 26;
                    g4 += ns[sv];
                    if(g4 >= 26){
                        g4 -= 26;
                    }
                }
            }
        }
        sv++;
        int n = toupper(l) - 'A';
        int k = (rt1[(n+g1)%26]-g1+26)%26;
        n = (rt2[(k+g2)%26]-g2+26)%26;
        k = (rt3[(n+g3)%26]-g3+26)%26;
        n = (rt4[(k+g4)%26]-g4+26)%26;
        k = rlf[n];
        n = (iv4[(k+g4)%26]-g4+26)%26;
        k = (iv3[(n+g3)%26]-g3+26)%26;
        n = (iv2[(k+g2)%26]-g2+26)%26;
        k = (iv1[(n+g1)%26]-g1+26)%26;
        cd += char(k + 'A');}
    }
    std::cout<<cd<<std::endl;
    dnv();
}
int main(){
    char y;
    std::cout<<"Want to use enyg?[y/n]"<<std::endl;
    std::cin>>y;
    if(tolower(y) == 'y' || tolower(y) == 's'){
        std::cout<<"type 6 nums from 1 to 9"<<std::endl;
        std::cin>>s1>>s2>>s3>>s4>>s5>>s6;   
        coddcod(); 
    }
    system("PAUSE");
    return 0;
}
