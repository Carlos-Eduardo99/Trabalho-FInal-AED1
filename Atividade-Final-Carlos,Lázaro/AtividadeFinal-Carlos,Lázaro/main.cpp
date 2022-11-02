#include <iostream>
#include <locale.h>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;

void arte(){//procedimento respons�vel por criar o cabe�alho do programa.

    cout << " _    _                           _____              "<<endl;
    cout << "| |  | |                         |  __ \             "<<endl;
    cout << "| |__| | __ _ _ __  _ __  _   _  | |  | | ___   __ _ "<<endl;
    cout << "|  __  |/ _` | ' _ \| '_  | | | | | |  | |/    |/ _` |"<<endl;
    cout << "| |  | | (_| | |_) | |_) | |_| | | |__| | (_) | (_| |"<<endl;
    cout << "|_|  |_||____| .__/| .__/ \__,  | |_____/ |____/ \__, |"<<endl;
    cout << "             | |   | |     __/ |                __/ |"<<endl;
    cout << "             |_|   |_|    |___/                |___/ "<<endl;
}

int valor(string tosa,string vacina,string codigo){// fun��o respons�vel por armazenar em arquivo as op��es escolhidas.
    fstream arq;
    string escreve,valores[3];
    valores[0]=tosa;
    valores[1]=vacina;
    valores[2]=codigo;

    arq.open("valores.txt" ,ios::app);
    escreve="";
    if(arq.is_open()){
    for (int i=0; i<=2;i++){ //passando as informa��es de compra e um c�digo para o escreve e adicionando tokens.
            if (i <2){
                escreve = escreve + valores[i] + ";";
            }
            else{
                escreve = escreve + valores[i] + ";\n";
            }
        }
        arq << escreve; //armazena a vari�vel escreve no arquivo.
    }
    arq.close();
    return 0;
}

int reg(){//fun��o respons�vel por registrar o atendimento de um cliente.
    fstream arq;
    arq.open("registro.txt", ios::app);
    string cabecalho[6];//vetor que guardar� as perguntas.
    cabecalho[0]="Nome do cliente";
    cabecalho[1]="Tosa(S/N)";
    cabecalho[2]="Banho (S/N)  Valor:R$35,00";
    cabecalho[3]="Vacina��o(S/N)";
    cabecalho[4]="Data do Registro";
    cabecalho[5]="C�digo de atendimento";
    bool k;
    string registro[6],escreve,tosa,vacina,codigo;

    do{
    //prennchendo uma linha de cadastro.
    for(int c=0;c<6;c++){
        cout << cabecalho[c]<<": ";
        cin >> registro[c];
        codigo=registro[5];
        if (c==1){
            if (registro[c]=="S"){ //se o cliente optar por tosa, mostra as op��es.
               cout<<"Tipos de Tosa:"<<endl;
               cout<<" ________________________________________________"<<endl;
               cout<<"|Digite 1:Para tosa (higi�nica)   Valor:R$15,00; |"<<endl;
               cout<<"|Digite 2:Para tosa (completa)    Valor:R$25,00; |"<<endl;
               cout<<"|Digite 3:Para tosa (tesoura)     Valor:R$55,00; |"<<endl;
               cout<<" ------------------------------------------------ "<<endl;
               cout<<"C�digo de opera��o: ";
               cin>>tosa; //guarda a op��o escolhida
               cout<<" "<<endl;
            }
            else{
                tosa="0";
            }
        }
      if (c==3){
         if (registro[c]=="S"){//se o cliente optar por vacinar seu animal, mostra as op��es.
            cout<<"Selecione a vacina que voc� deseja aplicar:"<<endl;
            cout<<" ______________________________________________________"<<endl;
            cout<<"|Digite 1:Para vacina (Anti-r�bica)    Valor:R$75,00;  |"<<endl;
            cout<<"|Digite 2:Para vacina (Bronchi/Tosse)  Valor:R$120,00; |"<<endl;
            cout<<"|Digite 3:Para vacina (V10)            Valor:R$100,00; |"<<endl;
            cout<<"|Digite 4:Para vacina (Gi�rdia)        Valor:R$115,00; |"<<endl;
            cout<<"|Digite 5:Para vacina (V4)             Valor:R$110,00; |"<<endl;
            cout<<" ------------------------------------------------------ "<<endl;
            cout<<"C�digo de opera��o: ";
            cin>>vacina;//guarda a op��o escolhida
            cout<<" "<<endl;
        }
           else{
              vacina="0";
           }
    }
    }
    escreve="";
    if(arq.is_open()){
    for (int i=0; i<=5;i++){//passando as informa��es do cadastro para o escreve e adicionando tokens.
            if (i <5){
                escreve = escreve + registro[i] + ";";
            }
            else{
                escreve = escreve + registro[i] + ";\n";
            }
        }
        arq << escreve; //armazena a vari�vel escreve no arquivo.
    }
    cout << "Outro cadastro(1), mudar opera��o(0): ";
    cin >>k;
    valor(tosa,vacina,codigo); //chamada da fun��o valor, que recebe por par�metro o tipo de tosa,vacina e o c�digo de atendimento.
    }while(k==1);
    arq.close();
    return 0;
}

void services(string vet[],int tosa,int vacina){//procedimento respons�vel por mostrar os servi�os prestados e o valor deles.
        if (vet[1]=="S"){//comparando e retornando os valores.
           cout<<" Banho - Valor:R$35,00"<<endl;
        }
        if (vet[0]=="S"){
           if (tosa==2){
              cout<<" Tosa (higi�nica) - Valor:R$15,00"<<endl;
           }
           if (tosa==3){
              cout<<" Tosa (completa) - Valor:R$25,00"<<endl;
           }
           if (tosa==4){
              cout<<" Tosa (tesoura) - Valor:R$55,00"<<endl;
           }
        }
        if (vet[2]=="S"){
           if (vacina==5){
              cout<<" Vacina (Anti-r�bica) - Valor:R$75,00"<<endl;
           }
           if (vacina==6){
              cout<<" Vacina (Bronchi/Tosse) - Valor:R$120,00"<<endl;
           }
           if (vacina==7){
              cout<<" Vacina (V10) - Valor:R$100,00"<<endl;
           }
           if (vacina==8){
              cout<<" Vacina (Gi�rdia) - Valor:R$115,00"<<endl;
           }
           if (vacina==9){
              cout<<" Vacina (V4) - Valor:R$110,00"<<endl;
           }
        }
}

void boleto(int valor,string vet1[],string vet2[],int t,int v){// respons�vel por gerar o boleto da compra.

    cout<<" _____________________________________________"<<endl;
    cout<<"             PetShow Happy Dog                "<<endl;
    cout<<"                                              "<<endl;
    cout<<" Nome do cliente: "<<vet1[0]<<"               "<<endl;
    cout<<" Data do registro: "<<vet1[4]<<"              "<<endl;
    cout<<"                                              "<<endl;
    cout<<" Servi�os prestados:                          "<<endl;
    cout<<"                                              "<<endl;
    services(vet2,t,v); //chamando o procedimento services, que recebe por paramentro as compras e o valor delas.
    cout<<"                                              "<<endl;
    cout<<" Valor � pagar: R$"<<valor<<",00"<<"          "<<endl;
    cout<<"                                              "<<endl;
    cout<<" Obrigado pela prefer�ncia!! Volte sempre!!   "<<endl;
    cout<<" ---------------------------------------------"<<endl;
}

int tosa(string codigo){ //respons�vel por retornar o valor da tosa para a fun��o Faten.
    string dados[3];
    fstream arq;
    string linha,token;
    int c;

    arq.open("valores.txt", ios::in);

    if (arq.is_open()){
        while (!arq.eof()){
                getline(arq,linha);
                c=0;
                for (int i=0; i<linha.size();i++){
                    if  (linha[i] != ';'){
                        token = token+linha[i];
                    }
                    else{
                        dados[c] = token;
                        token="";
                        c++;
                    }
                }
                if (dados[2]==codigo){//comparando o valor do vetor com o c�digo
                   if (dados[0]=="1"){
                      return 2;
                   }
                   if (dados[0]=="2"){
                      return 3;
                   }
                   if (dados[0]=="3"){
                      return 4;
                   }
                   else{
                      return 0;
                   }
                }
         }

     }
     arq.close();
     return 0;
}

int vacina(string codigo){ //respons�vel por retornar o valor da vacina para a fun��o Faten.
    string dados[3];
    fstream arq;
    string linha,token;
    int c;

    arq.open("valores.txt", ios::in);

    if (arq.is_open()){
        while (!arq.eof()){
                getline(arq,linha);
                c=0;
                for (int i=0; i<linha.size();i++){
                    if  (linha[i] != ';'){
                        token = token+linha[i];
                    }
                    else{
                        dados[c] = token;
                        token="";
                        c++;
                    }
                }
               if (dados[2]==codigo){
                  if (dados[1]=="1"){
                     return 5;
                  }
                  if (dados[1]=="2"){
                     return 6;
                  }
                  if (dados[1]=="3"){
                     return 7;
                  }
                  if (dados[1]=="4"){
                     return 8;
                  }
                  if (dados[1]=="5"){
                     return 9;
                  }
                  else{
                      return 0;
                  }
              }
         }

     }
     arq.close();
     return 0;
}

int Faten(){ //fun��o respons�vel por finalizar um atendimento.
    bool k;
    string dados[6];
    fstream arq;
    string linha,token,codigo,vet[3];
    int c,valor=0,valor1=0,valor2=0,preco[10],total,t,v;
    //armazenando os valores dos servi�os no vetor.
    preco[0]=0;
    preco[1]=35;
    preco[2]=15;
    preco[3]=25;
    preco[4]=55;
    preco[5]=75;
    preco[6]=120;
    preco[7]=100;
    preco[8]=115;
    preco[9]=110;

    do{
       arq.open("registro.txt", ios::in);
       cout<<"Digite o c�digo de atendimento para gerar o boleto da compra: ";//solicitando o c�digo de registro gerado pelo pr�prio usu�rio.
       cin>>codigo;
       if (arq.is_open()){
          while (!arq.eof()){
                getline(arq,linha);
                c=0;
                for (int i=0; i<linha.size();i++){ //lendo os dados armazenados em arquivo.
                    if  (linha[i] != ';'){
                        token = token+linha[i];
                    }
                    else{ //preenchendo o vetor com os dados lidos.
                        dados[c] = token;
                        token="";
                        c++;
                    }
                }
                if (dados[5]==codigo){ //comparando o c�digo digitado com um c�digo �nico do vetor
                   for (int j=1;j<=3;j++){
                        if (dados[1]=="S"){
                           valor1=preco[tosa(codigo)]; //chamada da fun��o tosa.
                           vet[0]="S";
                           t=tosa(codigo);//atribuindo o valor da fun��o tosa � vari�vel t.
                        }
                        else{
                           valor1=0;
                           vet[0]="N";
                           t=0;
                        }
                        if (dados[2]=="S"){
                           valor=preco[1];
                           vet[1]="S";
                        }
                        else{
                           valor=0;
                           vet[1]="N";
                        }
                        if (dados[3]=="S"){
                           valor2=preco[vacina(codigo)];//chamada da fun��o vacina.
                           vet[2]="S";
                           v=vacina(codigo);//atribuindo o valor da fun��o vacina � vari�vel v.
                        }
                        else{
                           valor2=0;
                           vet[2]="N";
                           v=0;
                        }
                   }
                total=valor+valor1+valor2;
                boleto(total,dados,vet,t,v);
                total=0;
                }

         }

     }
     cout << "Gerar outro boleto(1),Voltar ao menu principal(0): ";
     cin >> k;
     arq.close();
    }while(k==1);
    return 0;
}

int Dcon(){ //fun��o respons�vel por coletar uma data e retornar todos os cadastros feito na mesma.
    bool k;
    string dados[8],cabecalho[8];
    fstream arq;
    string linha,token, data;
    int l=0,c=0,cont=0;

    cabecalho[0]="Nome do dono";
    cabecalho[1]="Nome do animal";
    cabecalho[2]="Ra�a do animal";
    cabecalho[3]="Cor do animal";
    cabecalho[4]="Porte do animal(P/M/G)";
    cabecalho[5]="Sexo do animal(M/F)";
    cabecalho[6]="Vacinado(S/N)";
    cabecalho[7]="Data do Cadastro";

    do{
       arq.open("cadastro.txt", ios::in);
       cout<<"Qual data deseja consultar (xx/xx/xxxx)?: "; //solicitando uma data.
       cin >> data;
       cout<<" "<<endl;

       if (arq.is_open()){
          while (!arq.eof()){
                getline(arq,linha);
                c=0;
                for (int i=0; i<linha.size();i++){//processo de leitura de dados no arquivo.
                    if  (linha[i] != ';'){
                        token = token+linha[i];
                    }
                    else{
                        dados[c] = token;//guardando os dados lidos em um vetor.
                        token="";
                        c++;
                    }
                }
                l++;
                if (dados[7]==data){//comparando a data que veio do arquivo com o nome pedido na consulta.
                   for (int j=0; j<8; j++ ){
                       cout<<cabecalho[j]<<": "<<dados[j]<<endl; //escrevendo os dados.
                       cont=cont+1;
                   }
                   cout << endl;
                }
         }
         if (cont<1){ //mostrar quando a data n�o for encontrada.
         cout<<"A data "<<data<<" n�o foi encontrada em nossos registros"<<endl;
         cout<<" "<<endl;
         }
     }

     cout << "Consultar outra data(1),Voltar ao menu principal(0): ";
     cin >> k;
     arq.close();
    }while(k==1);
    return 0;
}

void Ccon(){//fun��o respons�vel por retornar os dados de um cliente.
    bool k;
    string dados[8],cabecalho[8];
    fstream arq;
    string linha,token, cliente;
    int l=0,c=0,cont=0;

    cabecalho[0]="Nome do dono";
    cabecalho[1]="Nome do animal";
    cabecalho[2]="Ra�a do animal";
    cabecalho[3]="Cor do animal";
    cabecalho[4]="Porte do animal(P/M/G)";
    cabecalho[5]="Sexo do animal(M/F)";
    cabecalho[6]="Vacinado(S/N)";
    cabecalho[7]="Data do Cadastro";

    do{
    arq.open("cadastro.txt", ios::in);
    cout << "Digite o nome cliente para saber seus dados: "; //solicitando o nome de um cliente.
    cin >> cliente;
    cout<<" "<<endl;
    if (arq.is_open()){
        while(!arq.eof()){
            getline(arq,linha);
            c=0;
            for(int i=0; i<linha.size();i++){//processo de leitura de dados no arquivo.
                if(linha[i] != ';'){
                    token = token+linha[i];

                }else{
                    dados[c] = token; //guardando os dados lidos em um vetor.
                    token="";
                    c++;
                }
            }
            l++;
             if(!arq.eof()){

            if (dados[0]==cliente){//comparando o nome que veio do arquivo com o nome pedido na consulta.
               for(int j=0; j<8; j++ ){
                    cout <<cabecalho[j]<<": "<<dados[j]<<endl; //retorna os dados do cliente.
                    cont=cont+1;
                }
                cout << endl;}
            }
       }
       if (cont==0){ //mostrar quando cliente n�o for encontrado.
          cout<<"O nome "<<cliente<<" n�o foi encontrada em nossos registros!"<<endl;
          cout<<" "<<endl;
       }
       cont=0;
    }

    cout << "Consultar outro cliente(1)/Voltar ao menu principal(0): ";
    cin >> k;
    arq.close();
    }while(k==1);

}

int cad(){ //fun��o respons�vel coletar e guardar em arquivo os dados de clientes cadastrados.
    fstream arq;
    arq.open("cadastro.txt", ios::app);
    string cabecalho[8];//vetor que guardar� as perguntas.
    cabecalho[0]="Nome do dono";
    cabecalho[1]="Nome do animal";
    cabecalho[2]="Ra�a do animal";
    cabecalho[3]="Cor do animal";
    cabecalho[4]="Porte do animal(P/M/G)";
    cabecalho[5]="Sexo do animal(M/F)";
    cabecalho[6]="Vacinado(S/N)";
    cabecalho[7]="Data do Cadastro";

    bool k; //vari�vel l�gica que define se o cadastro ir� continuar ou parar.
    string cadastro[8]; //vetor que coletar� as informa��es para o cadastro.
    string escreve; //vari�vel que ser� escrita no arquivo.
    do{
    //prennchendo uma linha de cadastro.
    for(int c=0;c<8;c++){
        cout << cabecalho[c]<<": ";
        cin >> cadastro[c];
    }
    escreve="";
    if(arq.is_open()){ //se o arquivo estiver aberto, a a��o ser� realizada.
    for (int i=0; i<=7;i++){ //passando as informa��es do cadastro para o escreve e adicionando tokens.
            if (i <7){
                escreve = escreve + cadastro[i] + ";";
            }
            else{
                escreve = escreve + cadastro[i] + ";\n";
            }
        }
        arq << escreve; //armazena a vari�vel escreve no arquivo.
    }
    cout << "Outro cadastro(1), mudar opera��o(0): ";
    cin >>k;
    }while(k==1);
    arq.close();
    return 0;
}

void menu(){//procedimento para mostrar os c�digos de opera��es e receber o c�digo.

    int i;
    do{
        arte();//chamada do procedimento arte, que criar� o titulo do programa.
        cout << "=======-Ol�!, qual opera��o deseja realizar?-======="<<endl;
        cout << " ____________________________________________________"<<endl;
        cout << "|Digite 1: Para cadastrar um novo animal;            |"<<endl;
        cout << "|Digite 2: Para registrar um atendimento;            |"<<endl;
        cout << "|Digite 3: Para finalizar um atendimento;            |"<<endl;
        cout << "|Digite 4: Para consultar uma data;                  |"<<endl;
        cout << "|Digite 5: Para consultar um cliente;                |"<<endl;
        cout << "|Digite 6: Para finalizar o programa.                |"<<endl;
        cout << " ----------------------------------------------------"<<endl;
        cout << "C�digo de opera��o: ";
        cin >> i;
        //verifica��o do c�digo
        switch(i){
            case 1:
                cad();//caso 1, chama o procedimento cadastro
            break;
            case 2:
                reg();//caso 2, chama a fun��o registro de um atendimento.
            break;
            case 3:
                Faten();//caso 3, chama a fun��o que finaliza um atendimento.
            break;
            case 4:
                Dcon();//caso 4, chama a fun��o que consulta uma data.
            break;
            case 5:
                Ccon();//caso 5, chama a fun��o que consulta um cliente.
            break;
            case 6:
                break;//caso 6, finaliza o programa.
            default:
                cout << "Que tal digitar um n�mero entre 1 a 6 da pr�xima vez?";
        }
        system("cls");//limpa a tela para chamada do novo menu.
    }while(i!=6);
}

int main(){//bloco principal, chama o procedimento menu.
    setlocale(LC_ALL,"portuguese");

    menu(); //chamada do procedimento menu.

    return 0;
}
