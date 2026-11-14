#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>

class pos {
    public:
    int ir1, ir2, ir3, ir4, ir5;
    int ls1, ls2, ls3, ls4, ls5, ls6, ls7, ls8;
    int ot0, ot1, ot2, ot3, ot4, ot5, ot6, ot7, ot8, ot9, ota, otb, otc, otd, ote, otf;
};
class msg {
    public:
    std::string txt;
};
class wr{
    public:
    char cd;
    bool func;
    bool way;
};
wr tme;
wr nw;
wr cd;
msg txin;
msg txeny;
msg txout;
pos posicao;
pos codica;
void intro(){
    if(nw.func == false){
        std::cout<<"Quer criptografar ou descriptografar?[C/D]"<<"\n"<<std::endl;
    }
    else{
        if(nw.func == true){
            if(tme.way == false){
                std::cout<<"diga cinco numeros (0 a 26) para definir a posicao inicial dos discos \n";
            }
            else{
                std::cout<<"diga oito numeros (0 a 10) para as chaves \n";
            }
        }
    }
}
void in(){
    std::cout<<"diga sua palavra/frase"<<std::endl;
}
int enyg(){
    int g1 = posicao.ir1, g2 = posicao.ir2, g3 = posicao.ir3, g4 = posicao.ir4, g5 = posicao.ir5;
    int rta[26] = {25, 13, 5, 4, 10, 9, 24, 6, 17, 20, 3, 22, 16, 12, 15, 0, 8, 1, 21, 23, 2, 7, 11, 14, 19, 18};
    int rtb[26] = {0, 13, 20, 8, 2, 12, 19, 15, 11, 10, 7, 17, 18, 1, 3, 5, 4, 14, 16, 6, 9, 25, 23, 21, 24, 22};
    int rtc[26] = {22, 19, 21, 11, 25, 2, 6, 16, 1, 4, 0, 5, 15, 3, 12, 18, 17, 20, 7, 10, 24, 8, 9, 13, 14, 23};
    int rtd[26] = {9, 0, 2, 3, 5, 1, 4, 6, 12, 7, 15, 19, 13, 18, 24, 8, 10, 11, 14, 16, 20, 17, 22, 21, 25, 23};
    int rte[26] = {0, 10, 20, 1, 11, 21, 2, 12, 22, 3, 13, 23, 4, 14, 24, 5, 15, 25, 6, 16, 7, 17, 8, 18, 9, 19};
    int rlf[26] = {5, 3, 4, 1, 2, 0, 14, 10, 9, 8, 7, 15, 20, 16, 6, 11, 13, 25, 22, 21, 12, 19, 18, 24, 23, 17};
    int iva[26], ivb[26], ivc[26], ivd[26], ive[26];
    for(int i = 0; i <= 25; i++){
        iva[rta[i]] = i;
        ivb[rtb[i]] = i;
        ivc[rtc[i]] = i;
        ivd[rtd[i]] = i;
        ive[rte[i]] = i;
    }
    int pss = 0;
    int som[8] = {codica.ls1, codica.ls2, codica.ls3, codica.ls4, codica.ls5, codica.ls6, codica.ls7, codica.ls8};
    for(char s : txin.txt){
        if(!isalpha(s)){
            txeny.txt += s;
        }
        else{
            if(pss > 7){
                pss = 0;
            }
            g1 += som[pss];
            if(g1 >= 26){
                g1 -= 26;
                g2 += som[pss];
                if(g2 >= 26){
                    g2 -= 26;
                    g3 += som[pss];
                    if(g3 >= 26){
                        g3 -= 26;
                        g4 += som[pss];
                        if(g4 >= 26){
                            g4 -= 26;
                            g5 += som[pss];
                            if(g5 >= 26){
                                g5 -= 26;
                            }
                        }
                    }
                }
            }
            pss++;
            int n = toupper(s) - 'A';
            int k = (rta[(n+g1)%26]-g1+26)%26;
            n = (rtb[(k+g2)%26]-g2+26)%26;
            k = (rtc[(n+g3)%26]-g3+26)%26;
            n = (rtd[(k+g4)%26]-g4+26)%26;
            k = (rte[(n+g5)%26]-g5+26)%26;
            n = rlf[k];
            k = (ive[(n+g5)%26]-g5+26)%26;
            n = (ivd[(k+g4)%26]-g4+26)%26;
            k = (ivc[(n+g3)%26]-g3+26)%26;
            n = (ivb[(k+g2)%26]-g2+26)%26;
            k = (iva[(n+g1)%26]-g1+26)%26;
            txeny.txt += char(k + 'A');
        }
    }
    return 0;
}
int vege(){
    char l;
    pos key;
    int chave[16] = {key.ot0 = codica.ls1, key.ot1 = (codica.ls1 + codica.ls2), key.ot2 = codica.ls3, key.ot3 = (codica.ls3+codica.ls4), key.ot4 = codica.ls5, key.ot5 = (codica.ls5 + codica.ls6), key.ot6 = codica.ls7, key.ot7 = (codica.ls7 + codica.ls8), key.ot8 = codica.ls2, key.ot9 = codica.ls4, key.ota = codica.ls6, key.otb = codica.ls8, key.otc = (codica.ls2 + codica.ls4), key.otd = (codica.ls4 + codica.ls6), key.ote = (codica.ls6 + codica.ls8), key.otf = (codica.ls2 + codica.ls8)};
    msg nere;
    int vz = 0;
    for(char v : txeny.txt){
        if(vz >= 16){
            vz = 0;
        }
        if(!isalpha(v)){
            nere.txt += v;
        }
        else{
            int n = toupper(v) - 'A';
            nere.txt += char(((((chave[vz])%26)+ n)%26) + 'A');
            vz++;
        }}
    txout.txt = nere.txt;
    return 0;
}
int revege(){
    char l;
    pos key;
    int chave[16] = {key.ot0 = codica.ls1, key.ot1 = (codica.ls1 + codica.ls2), key.ot2 = codica.ls3, key.ot3 = (codica.ls3+codica.ls4), key.ot4 = codica.ls5, key.ot5 = (codica.ls5 + codica.ls6), key.ot6 = codica.ls7, key.ot7 = (codica.ls7 + codica.ls8), key.ot8 = codica.ls2, key.ot9 = codica.ls4, key.ota = codica.ls6, key.otb = codica.ls8, key.otc = (codica.ls2 + codica.ls4), key.otd = (codica.ls4 + codica.ls6), key.ote = (codica.ls6 + codica.ls8), key.otf = (codica.ls2 + codica.ls8)};
    msg nere;
    int vz = 0;
    for(char v : txin.txt){
        if(vz >= 16){
            vz = 0;
        }
        if(!isalpha(v)){
            nere.txt += v;
        }
        else{
            int n = toupper(v) - 'A';
            int seg = (n - (chave [vz]%26) + 26)%26;
            nere.txt += char(seg + 'A');
            vz++;
        }
    }
    txin.txt = nere.txt;
    return 0;
}
int rm(){
    std::reverse(txout.txt.begin(), txout.txt.end());
    txin.txt = txout.txt;
    if(tme.func == true){
        txeny.txt = "";
        enyg();
    }
    return 0;
}
int decry(){
    txeny.txt = "";
    enyg();
    tme.func = false;
    txout.txt = txeny.txt;
    rm();
    revege();
    txeny.txt = "";
    enyg();
    return 418;
}
int crip(){
    txeny.txt = "";
    enyg();
    vege();
    rm();
    return 0;
}
int main(){
    wr vz;
    vz.way = true;
    while (vz.way == true){
        std::cout<<"quer usar o zyg?[s/n]"<<std::endl;
        std::cin>>nw.cd;
        if(tolower(nw.cd) == 'n'){
            vz.way = false;
            return 0;
        }
        else if(tolower(nw.cd) != 's' && tolower(nw.cd) != 'n'){
            std::cout<<"vai tomar cafe"<<std::endl;
            system("PAUSE");
            return 418;
        }
        nw.func = false;
        intro();
        std::cin>>cd.cd;
        if(tolower(cd.cd) == 'c'){
            tme.func = true;
            cd.way = false;
        }
        else if (tolower(cd.cd) == 'd'){
            cd.way = true;
        }
        else{
            std::cout<<"ERRO";
            system("PAUSE");
            return 404;
        }
        nw.func = true;
        tme.way = false;
        intro();
        std::cin>>posicao.ir1>>posicao.ir2>>posicao.ir3>>posicao.ir4>>posicao.ir5;
        tme.way = true;
        intro();
        std::cin>>codica.ls1>>codica.ls2>>codica.ls3>>codica.ls4>>codica.ls5>>codica.ls6>>codica.ls7>>codica.ls8;
        in();
        std::cin.ignore();
        std::getline(std::cin, txin.txt);
        if(cd.way == false){
            crip();
        }
        else{
            decry();
        }
        std::cout<<txeny.txt<<std::endl;
        }
    return 0;
}
