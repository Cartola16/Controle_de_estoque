#ifndef ESTOQUEV4_H_INCLUDED
#define ESTOQUEV4_H_INCLUDED


#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <typeinfo>
#include <windows.h>
#include <io.h>
#include <ostream>
#include <cstring>
#include <bits/stdc++.h>
#include <string>
#include <conio.h>
#include <fstream>
#define p <<endl;
#define pp <<endl
#define linha cout pp <<"-----------------------------------------------------------------" p
#define sp cout pp pp p


using namespace std;



auto rodando=true;

    char exclui[50]="kk";
    char nomes[1000][50];
    char lg[40];
    int qtds[1000];
    float precos[1000];
    int cont=0,tam=0;
    bool voice=true;
    clock_t  t1=clock();

void atualiza_login()
{
     time_t ll;
    FILE *lastlo=fopen("last_login.txt","w");
    time(&ll);
    fprintf(lastlo,"%s",ctime(&ll));

    fclose(lastlo);
}

void mode_voice(char op)
{
    switch(op)
    {
    case 'S':
        case 's':voice=true;break;

        case 'n':
            case 'N':voice=false;break;

            default:cout<<"Não temos essa opção" p;voice=true;break;
    }
}

void login()
{

    fstream LL;
    LL.open("last_login.txt",fstream::in);
    LL.read(lg,40);
    LL.close();
}

void show_ll()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    printf("\nLast login: ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    printf("%s\n",lg);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

}

void atualiza()
{


    FILE *f1=fopen("armazem.txt","r");
	char nome[1000];
	float preco;
	int qtd;


    while(fscanf(f1,"%s %d %f",nomes[cont],&qtds[cont],&precos[cont])!=EOF)
    {


        cont++;
        tam++;

    }


    fclose(f1);
    /*for(int i=0;i<sizeof(qtds)/4;i++)
    {
        cout<<nomes[i]<<" "<<qtds[i]<<" "<<precos[i] p
    }*/
}



void finaliza()
{
    FILE *f2=fopen("armazem.txt","w");

    char exclui[50]="kk";
    int res;
        for(int a=0;a<tam;a++)
        {

            res=strcmp(nomes[a],exclui);
            if(res!=0)
            {
            fprintf(f2,"%s %d %f\n",nomes[a],qtds[a],precos[a]);
            }

        }

     fclose(f2);

    clock_t t2=clock();
    clock_t t3=difftime(t2,t1);
     cout pp<<"Time operating: "<<((float)t3)/CLOCKS_PER_SEC<<"s" p
}


void cls()
{
    system("cls");
}


void edit(){

        char prod[50];
        char nprod[50];
        float np;
        int nq;

        cout<<"Produto: ";
        gets(prod);
        cout pp<<"Novo nome: ";
        gets(nprod);
        cout pp<<"Novo preço: ";
        cin>>np;
        cout pp<<"Nova quantidade: ";
        cin>>nq;

        int res;
        for(int kk=0;kk<tam;kk++)
        {
            res=strcmp(prod,nomes[kk]);
            if(res==0)
            {
                strcpy(nomes[kk],nprod);
                precos[kk]=np;
                qtds[kk]=nq;
                break;
            }else{
                continue;
            }
        }

        if(voice)
        {
            fstream voz;
            voz.open("consultora.vbs",fstream::out);
            voz <<"dim sapi" p
            voz <<"Set sapi =CreateObject(\"sapi.spvoice\")" p
            voz <<"sapi.Speak \" ";
            voz <<"Produto ";
            voz.write(prod,strlen(prod));
            voz <<" Foi alterado para ";
            voz.write(nprod,strlen(nprod));
            voz<<"\"";
            voz.close();

            char teste[500]="start ";
            strcat(teste,"consultora.vbs");
            system((const char*)teste);


        }
}

void del(){

    char eprod[50];
    cout<<"Entre com o produto a ser excluido: ";
    gets(eprod);

    int res;
    char eprod2[50];
    strcpy(eprod2,eprod);
    for(int kk=0;kk<tam;kk++)
    {
    res=strcmp(eprod,nomes[kk]);
            if(res==0)
            {
                strcpy(eprod,"kk");
                strcpy(nomes[kk],eprod);
                precos[kk]=0;
                qtds[kk]=0;
                break;
            }else{
                continue;
            }
    }

    if(voice)
        {
            fstream voz;
            voz.open("consultora.vbs",fstream::out);
            voz <<"dim sapi" p
            voz <<"Set sapi =CreateObject(\"sapi.spvoice\")" p
            voz <<"sapi.Speak \" ";
            voz <<"Produto ";
            voz.write(eprod2,strlen(eprod));
            voz <<" Foi deletado ";
            voz<<"\"";
            voz.close();

            char teste[500]="start ";
            strcat(teste,"consultora.vbs");
            system((const char*)teste);


        }

}

void destroy(){


        if(remove("armazem.txt")==NULL)
        {
            printf("Estoque removido\n");
        }else{
        printf("Estoque não removido\n");
        }

}
void tempo()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
    clock_t to=clock();
    cout<<"Time operating: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
    cout<<((float)to)/CLOCKS_PER_SEC<<"s" pp p
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}

void add(){

    int quan;
    float pre;



    cout pp<<"Nome: ";
    gets(nomes[cont]);
    cout pp<<"Preço: ";
    cin>>precos[cont];
    cout pp<<"Quantidade: ";
    cin>>qtds[cont];
    cont++;
    tam++;

    if(voice)
        {
            fstream voz;
            voz.open("consultora.vbs",fstream::out);
            voz <<"dim sapi" p
            voz <<"Set sapi =CreateObject(\"sapi.spvoice\")" p
            voz <<"sapi.Speak \" ";
            voz <<"Produto ";
            voz.write(nomes[cont],strlen(nomes[cont]));
            voz <<" Foi adicionado";
            voz<<"\"";
            voz.close();

            char teste[500]="start ";
            strcat(teste,"consultora.vbs");
            system((const char*)teste);


        }

}



void show()
{

    printf("|");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
    printf(" Produto ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    printf("|");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    printf(" Quantidade ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    printf("|");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
    printf(" Preço ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    for(int i=0;i<tam;i++)
    {

        if(strcmp(nomes[i],exclui)!=0)
        {
        cout pp<<"---------------------------------------------------------" p
        printf("|");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
    printf(" %s ",nomes[i]);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    printf("|");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    printf(" %d ",qtds[i]);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    printf("|");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
    printf(" %.2f ",precos[i]);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        }
    }
    cout pp<<"---------------------------------------------------------" p
    cout p


}

void look()
{
    char prod[50];
    cout<<"Produto: ";
    gets(prod);

    int res;
    int kk;
        for(kk=0;kk<tam;kk++)
        {
            res=strcmp(prod,nomes[kk]);
            if(res==0)
            {
               printf("|");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
            printf(" Produto ");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            printf("|");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
            printf(" Quantidade ");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            printf("|");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
            printf(" Preço ");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            cout pp<<"---------------------------------------------------------" p
            printf("|");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
            printf(" %s ",nomes[kk]);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            printf("|");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
            printf(" %d ",qtds[kk]);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            printf("|");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
            printf(" %.2f ",precos[kk]);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            cout pp<<"---------------------------------------------------------" p


                break;
            }else{

                continue;
            }
        }

        if(kk==tam)
        {
            cout pp<<"Produto não encontrado!" p
        }

}


void exit()
{

    rodando=false;
    cout<<"Vlw flw" p
    if(voice)
        {
            fstream voz;
            voz.open("consultora.vbs",fstream::out);
            voz <<"dim sapi" p
            voz <<"Set sapi =CreateObject(\"sapi.spvoice\")" p
            voz <<"sapi.Speak \" ";
            voz <<"Falou VALEU";
            voz<<"\"";
            voz.close();

            char teste[500]="start ";
            strcat(teste,"consultora.vbs");
            system((const char*)teste);


        }

}

void mode()
{
    cout<<"Consultora: ";

    if(voice)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        cout<<"Ligada" p
    }else{

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
                cout<<"Desligada" p
    }


    }

void help()
{
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
            cout<<"Comandos:" pp<<"ls - mostra o conteudo do estoque" pp <<"cls - limpa a tela" p
            cout<<"add - adiciona um novo produto no estoque" pp <<"del - remove um produto do estoque" p
            cout<<"edit - modifica um produto do estoque" pp<<"help - mostra os comandos" pp<<"exit - sair do estoque" p
            cout<<"time - mostra o tempo decorrido desde o inicio do programa" p
            cout<<"find - procura um produto" p
            cout<<"ll - mostra o último login" p
            cout<<"on - liga a consultora" p
            cout<<"off - desliga a consultora" p
            cout<<"mode - mostra o estado daa consultora" p
            cout<<"-------------------------------------------" p
            cout<<"OBS::Quando adicionar um produto, coloque ponto(.) e não virgula(,) para as casas decimais" p
            cout<<"-------------------------------------------" pp p
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

}


void help_cmd()
{
    cout<<"Parâmetros:\n/h- Mostra todos os paramêtros disponíveis\n/s- mostra os produtos do estoque\n";
    cout<<"/a- adicion um produto\n";
}

#endif // ESTOQUEV4_H_INCLUDED
