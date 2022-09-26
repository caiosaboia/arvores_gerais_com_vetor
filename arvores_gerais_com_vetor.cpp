#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>

struct node{
    char valor;
    node* pai;
    std::vector<node*> filho;
};

class ARVORE{
private:
    node* raiz;
    void pre_ordem(node* p);
    void pos_ordem(node* p);
    void apaga(node* p);
    node* sub_arvore(std::string &S,int &i);
public:
    ~ARVORE();
    ARVORE(std::string S);
    void apaga_tudo();
    void pre_ordem();
    void pos_ordem();
    void nivel_ordem();
    void pre_ordem_naorec();
};

ARVORE::~ARVORE(){
    apaga_tudo();
}

void ARVORE::apaga_tudo(){
    apaga(raiz);
    raiz = NULL;
}

void ARVORE::apaga(node* p){
    if (p==NULL) return;
    for (int i = 0; i < p->filho.size(); i++){
        apaga(p->filho[i]);
    }
    delete p;
}

void ARVORE:: pre_ordem(node* p){
    if (p == NULL) return;
    std::cout << p->valor << " ";
    for (int i =0; i < p->filho.size(); i++){
        pre_ordem(p->filho[i]);
    }
}

void ARVORE::pre_ordem(){
    pre_ordem(raiz);
}

void ARVORE::pos_ordem(node* p){
    if (p==NULL) return;
    for(int i = 0; i < p->filho.size(); i++){
        pos_ordem(p->filho[i]);
    }
    std::cout << p->valor << " ";
}

void ARVORE::pos_ordem(){
    pos_ordem(raiz);
}

void ARVORE::nivel_ordem(){
    if (raiz== NULL) return;
    std::queue<node*> q;
    q.push(raiz);

    while(!q.empty()){
        node* p= q.front();
        q.pop();
        if (p==NULL) continue;
        std::cout << p->valor << " ";
        for (int i = 0; i < p->filho.size(); i++){
            if (p->filho[i] != NULL) q.push(p->filho[i]);
        }
    }
}

void ARVORE::pre_ordem_naorec(){
    if (raiz== NULL) return;
    std::stack<node*> q;
    q.push(raiz);
    while (!q.empty()){
        node* p = q.top();
        q.pop();
        if(p==NULL) continue;
        std::cout << p->valor << " ";
        for(int i= p->filho.size()-1; i >=0; i--){
            if (p->filho[i]!= NULL){
                q.push(p->filho[i]);
            }
        }
    }
}

std::string S = "(a (b (e) (f)) (c (g (k)(l (m (n (o)(p)(q)))))) (d (h)(i)(j)))";

ARVORE::ARVORE(std::string S){
    int i = 0;
    raiz = sub_arvore(S,i);
}

node* ARVORE::sub_arvore(std::string &S, int &i){
    while ((S[i]== '(') || (S[i]== ' ')) i++;
    if (S[i] == ')') {
        i++; return NULL;
    }
    node* p = new node;
    p->valor = S[i++];

    while(true) {
        node* q = NULL;
        q = sub_arvore(S,i);
        if (q== NULL) break;
        p->filho.push_back(q);
    }
    return p;
}

int main() {
    ARVORE T ("(a (b)(c)(d)");
    T.pre_ordem();
}





