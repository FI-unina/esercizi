#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct struttura{
    char campo1; //1
    int campo2; //4
    char campo3; //1
    int campo4; //4
};
// 1+4+1+4 =10

struct struttura2{
    char campo1;
    int campo2;
    char campo3;
    int campo4;
} var_struct1;

void modifica_campo_struct_ptr(struct struttura *s){

    s->campo1 = 'A'; // equivalentemente così s->campo1 = s->campo1 - 32;

}

void stampa_struct(struct struttura s){
    printf("s.campo1 = %c\n"   
            "s.campo2 = %d\n"
            "s.campo3 = %c\n"
            "s.campo4 = %d\n\n", s.campo1, s.campo2, s.campo3, s.campo4);
    
}

typedef struct {

    int a;
    int b;

} PROVA;


int main() {
    
    // dichiaro una struct alla maniera classica
    struct struttura s1;

    // dichiaro una struct usando un typedef
    typedef struct struttura STRUTTURA;

    STRUTTURA s2;
    PROVA s3;

    printf("sizeof(struttura): %lu\n", sizeof(struct struttura));

    // inizializzo la variabile della struct definita nel modo
    // definitizion struct e var di struct
    var_struct1.campo1 = 'a';
    var_struct1.campo2 = 0;
    var_struct1.campo3 = 'b';
    var_struct1.campo4 = 1;

    s1.campo1 = 'a';
    s1.campo2 = 0;
    s1.campo3 = 'b';
    s1.campo4 = 1;

    printf("STRUCT s1\n");
    stampa_struct(s1);
    
    modifica_campo_struct_ptr(&s1);
    printf("STRUCT s1 dopo la modifica passando per riferimento\n");
    stampa_struct(s1);    

    return 0;
}

