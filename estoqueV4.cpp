#include <iostream>
#include <locale.h>
#include <bits/stdc++.h>
#include <windows.h>
#include <stdlib.h>
#include <typeinfo>
#include <string.h>
#include <stdio.h>
#include <C:\Users\João Marcos\Documents\João Marcos - Cotec\Projetos Variados\C++\estoqueV4.h>
#define p <<endl;
#define pp <<endl
#define linha cout pp <<"-----------------------------------------------------------------" p
#define linhaarq pp <<"-----------------------------------------------------------------" p
#define limpa system("cls");
#define sp cout pp pp p


using namespace std;

string comando;

main(int argc,char* argv[])
{


//------tela inicial---
    int jmcs=1;
    int carregado=0;
    while(jmcs==1)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
        printf("\n\t\t ________                                      ");
        printf("\n\t\t|        |                                      ");
        printf("\n\t\t|________|                                    ");
        printf("\n\t\t|                                                ");
        printf("\n\t\t|                                             ");
        printf("\n\t\t|________                                     ");
        printf("\n\t\t|        |                                  ");
        printf("\n\t\t|________|                                   ");
        printf("\n\t\t|                                            ");
        printf("\n\t\t|                                            ");
        printf("\n\t\t|________    ____   _____   ___   ___         ___              ");
        printf("\n\t\t|        |  |_  .| |_____| |   | | . | |   | |___            ");
        printf("\n\t\t|________|  |____|   | |   |___| |_  | |___| |___             ");
        printf("\n\t\t                                   |_|      ");
        printf("\n\t\t                                                  {Version 4.3}");
        if(carregado==0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
        printf("\nCaregando");
        Sleep(1000);
        printf(".");
        Sleep(1000);
        printf(".");
        Sleep(1000);
        printf(".");
        carregado=1;
        system("cls");
        }else{
            printf("\nCarregado!\n");
            getch();
            jmcs=0;
        }


    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    char senha[20];
    char password[20];
    setlocale(LC_ALL,"portuguese");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    printf("password:");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    gets(senha);

    int res;
    FILE *senha_arq=fopen("senha.txt","r");
    while(fscanf(senha_arq,"%s",password)!=EOF)
    {
        res=strcmp(senha,password);
        if(res==0){break;}else{continue;}
    }

    fclose(senha_arq);


    if(res==0)
    {
    login();
    atualiza_login();
    atualiza();
    help();

//------------PROMPT
            while(rodando){


                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
                cout<<"root";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
                cout<<"@";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
                cout<<"user";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
                cout<<":";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
                cout<<"~";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                cout<<"#";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
                getline(cin,comando);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

            if(comando=="ls")
            {
                show();
            }
            else if(comando=="destroy"){
                destroy();

            }else if(comando=="cls")
            {
                cls();
            }else if(comando=="add")
            {
                add();
            }else if(comando=="help"){
                    help();
            }else if(comando=="del"){
                    del();
            }else if(comando=="edit"){
                edit();
            }else if(comando=="time"){
                tempo();

            }else if(comando=="find"){
                    look();

            }else if(comando=="on")
            {mode_voice('S');

            }else if(comando=="off"){
                mode_voice('n');

            }else if(comando=="ll")
            {
                show_ll();

            }else if(comando=="mode")
            {
                mode();

            }else if(comando=="exit"){

            exit();

            }else{
                cout<<"Sintaxe do comando "<<comando<<" está incorreta/não existe" pp p
            }
            }//fim do while



    //atualiza();
    finaliza();
    }else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
        cout<<"not found";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

    }


	return 0;
}
