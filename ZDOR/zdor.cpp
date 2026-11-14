#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>

class frase{
    public:
    bool wh, lp, psd;
    std::string iot;
    std::string sd;
    char s, t, u, v;
};
class w{
    public:
    bool vt;
};
w pb;
frase vd;
int de(){
    frase at;
    at.psd = false;
    vd.sd = "";
    at.lp = false;
    std::reverse(vd.iot.begin(), vd.iot.end());
    if(vd.iot.size() % 2 != 0){
        std::cout << "Invalid!" << std::endl;
        return 1;
    }

    for(size_t i = 0; i < vd.iot.size(); i += 2){
        char primeiro = vd.iot[i];
        char segundo = vd.iot[i+1];

        if(primeiro == segundo){
            vd.sd += primeiro;
        }
        else{
            vd.sd += segundo - 1;
        }
    }
    std::cout<<vd.sd<<std::endl;
    return 0;
}
int cr(){
    vd.sd = "";
    for(char a : vd.iot){
        if(tolower(a) == 'a' || tolower(a) == 'z' || !isalpha(a)){
            vd.sd += a;
            vd.sd += a;
        }
        else{
            vd.sd += a-1;
            vd.sd += a+1;
        }
    }
    std::reverse(vd.sd.begin(), vd.sd.end());
    std::cout<<vd.sd<<std::endl;
    return 0;
}
void txtout(){
    if(vd.wh == 0){
        std::cout<<"Wanna criptografy or decriptografy?[c/d]"<<std::endl;
    }
    else if(vd.wh == 1){
        std::cout<<"Text:\n";
    }
}
int main(){
    w ret;
    ret.vt = true;
    while(ret.vt == true){
        vd.wh = false;
        for(int i = 0; i < 2; i++){
            txtout();
            if(vd.wh == false){
                char cmp;
                std::cin>>cmp;
                if(tolower(cmp) == 'd'){
                    pb.vt = false;
                }
                else if(tolower(cmp) == 'c'){
                    pb.vt = true;
                }
                else{
                    std::cout<<"sorry, I cant make coffe because im a teapot"<<std::endl;
                    system("PAUSE");
                    return 418;
                }
                vd.wh = true;
            }
            else{
                std::cin.ignore();
                getline(std::cin, vd.iot);
            }
        }
        if(pb.vt == true){
            cr();
        }
        else{
            de();
        }
        std::cout<<"One more time? [1 se sim, 0 se nao]"<<std::endl;
        std::cin>>ret.vt;
    }
    return 0;
}
