#ifndef __DRIVER_H__
#define __DRIVER_H__


using namespace std;

#include <string>
#include <map>
#include <stack>
#include <vector>
#include "SimbolosTabla.h"
#include "TiposTabla.h"
#include "Pila.h"
#include "Lexer.h"
#include "parser.tab.hh"


class Driver
{
private:
    int dir;
    int numTemp;
    int numLabel;    
    int numType;
    int gType;
    int cteF;
    string gId;
    Pila* pilaSimbolos;
    //SymTab ts;
    //TypeTab tt;
    //vector<Quad> icode;
    //map<string, string> constantes;
    //Generator gen;
    //Pila<int> labelStack;

    Lexer *lexer=nullptr;
    yy::Parser *parser =nullptr;
public:
    Driver(/* args */);
    Driver(string file);
    ~Driver();

    void setFile(string file);
    void setType(int type);
    void setId(string id);

    void pushLabel(int label);
    void popLabel();
    int topLabel();
    int elemt(int i);
    // Funciones para generar código intermedio    
    string newLabel();
    string newLabel(int num);
    int newLab();
    string newTemp();
    void genCode(string res, string arg1, string op, string arg2);
    void _label(string label);
    void _goto(string label);
    void _if(string var, string label);
    string ampliar(string dir, int t1, int t2);
    string reducir(string dir, int t1, int t2);
    int max(int t1, int t2);    
    int min(int t1, int t2);

    //Funciones de análisis semántico
    void addSym(string id, int type, string cat);
    void addSym(string id, int dir, int type, string cat);
    void addSym(string id, int dir, int type, string cat, vector<int> args);
    int addType(string name, int items, int base);
    //int addType(string name, SymTab *tab);

    //
    Expresion mas(Expresion e1, Expresion e2);
    Expresion menos(Expresion e1, Expresion e2);
    Expresion mul(Expresion e1, Expresion e2);
    Expresion div(Expresion e1, Expresion e2);
    Expresion asig(string id, Expresion e);
    Expresion ident(string id);
    Expresion numero(string val, int type);
    void error(string msg);
    void print();
    void translate();

    void parse(const string& file);
    void parse_helper(istream &stream);

    int getGtype();
    string getId();

    Pila* getPilaTSimbolos();

    int getDir();

    void printTable();

    void pushTablaSimbolos();


};





#endif // !__DRIVER_HPP__
