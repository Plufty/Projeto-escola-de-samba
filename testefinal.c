/*Alunos: Gleidson Vinicius Gomes Barbosa - 6331
          Arthur Araujo Freitas - 6334           */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//trabalho todo feito e identado no notepad padrao do linux.
//Acentos e cedilhas retirados para enviar ao PVANet.
typedef struct sNotas
{
    float bater;//Bateria
    float sambaenr;//Samba-Enredo
    float harmonia;//Harmonia
    float evol;//Evolucao
    float enr;//Enredo
    float conjunto;//Conjunto
    float aleade;//Alegorias e Aderecos
    float fantasias;//Fantasia
    float comfrente;//Comissao de frente
    float msalapband;//Mestre-Sala e Porta-Bandeira
    float anim;//Animacao
    float dedi;//Dedicacao
    float org;//Organizacao
    float notageral;//Nota total
}Notas;   
typedef struct sJurados
{
    char nome[51];
    Notas n;
}Jurados;
typedef struct sEscola
{
    char nome[51];
    char resp[51];
    Jurados j[5];
}Escola;
int tamanho (char curto[])//Funcao para checagem de tamanho.
{
    int j,check;
    check=0;
    for(j=0;j<8;j++)
    {
        if (curto[j]=='\0')
        {
            check=1;
            break;
        } 
    }
    return check;
}
float somatorio (float *quesito,int pos)//Funcao para soma das notas.
{
    float resultado;
    if (pos==0)
    {
        resultado=quesito[pos];
    }
    else
    {
        resultado=quesito[pos]+somatorio(quesito,pos-1);
    }
    return resultado;
}
int descartamaior (float *nquesito)//Funcao para descartar maior nota.
{
    int k;
    int nmaior;
    float maior=0;
    for (k=0;k<5;k++)
    {
        if(nquesito[k]>maior)
        {
            maior=nquesito[k];
            nmaior=k;
        }
    }
    return nmaior;
}
int descartamenor (float *nquesito)//Funcao para descartar menor nota.
{
    int i;
    int nmenor;
    float menor=11;
    for (i=0;i<5;i++)
    {
        if(nquesito[i]<menor)
        {
            menor=nquesito[i];
            nmenor=i;
        }
    }
    return nmenor;
}
float calculamedia (float *quesito,int pos, int maior, int menor)//Funcao para media das notas.
{
    float resultado;
    if (pos==0)
    {
        resultado=(quesito[pos]-quesito[maior]-quesito[menor])/3.0;
    }
    else
    {
        resultado=quesito[pos]/3.0+calculamedia(quesito,pos-1, maior, menor);
    }
    return resultado;
}
void lideres (float lideres[], Escola escolas[], int nescola)//Funcao para lider e vice-lider.
{
    int i,j,k,l;
    int champion =0, vchampion=0;
    float maior=0,maior2=0;
    for (i=0;i<nescola;i++)
    {
        if (lideres[i]>maior)
        {
            maior=lideres[i];
            champion=i;
        }
    }
    for (k=0;k<nescola;k++)
    {
        if(k!=champion)
        {
            if (lideres[k]>maior2)
            {
                maior2=lideres[k];
                vchampion=k;
            }
        }
    }
    printf ("A escola campea com a notal geral de %.2f e: %s!!\n", lideres[champion], escolas[champion].nome);
    printf ("A escola vice campea com a notal geral de %.2f e: %s!!\n", lideres[vchampion], escolas[vchampion].nome); 
}
void rebaixadas (float rebaixadas[], Escola escolas[], int nescola)//Funcao para escolas rebaixadas
{
    int j,k;
    int r1=0, r2=0;
    float menor=11, menor2=11;
    for (j=0;j<nescola;j++)
    {
        if (rebaixadas[j]<menor)
        {
            menor=rebaixadas[j];
            r1=j;
        }
    }
    for (k=0;k<nescola;k++)
    {
        if (k!=r1)
        {
            if (rebaixadas[k]<menor2)
            {
                menor2=rebaixadas[k];
                r2=k;
            }
        }
    }
    printf ("Infelizmente duas escolas foram rebaixadas, sao elas: %s com a notal geral de %.2f e %s com a notal geral de %.2f.\n",escolas[r1].nome,rebaixadas[r1],escolas[r2].nome, rebaixadas[r2]); 
}
int procura (char busca[], Escola esc[], int nescola)//Funcao para buscar escolas pelo nome.
{
    int i,j;
    int check;
    for (i=0;i<nescola;i++)
    {
        if (check==i-1)
        {
            break;
        }
        for (j=0;j<51;j++)
        {
            if (busca[j] == '\0' || esc[i].nome[j] == '\0')
            {
                if (busca[j] == '\0' && esc[i].nome[j] == '\0')
                {
                    break;
                }
                else
                {
                    check=-1;
                    break;
                }
            }
            else	
            {
                if (busca[j] != esc[i].nome[j])
                {
                    check=-1;
                    break;
                }
                else
                {
                    check=i;
                }
            }
        }
    }
    return check;
}

int main()
{
    Escola *e;
    int numescola=0;//variavel do menu 1.
    char menue[51];//variavel do menu 2.
    int buscanome;//variavel do menu 2.
    int menu;//variavel do menu;
    int texto;//variavel do menu 8.
    int cadastrojurados=0;//Variavel do menu 3 usada para nomear os juizes.
    int v;//controle do menu de notas;
    int a,b,c,d,f,g,h,i,k,w,y,z;//Variaveis de controle para o for.
    int sn,teste,o;//Variaveis para o controle do cadastro.
    Jurados juri[5];
    int buscador=0;//variável do menu 2.
    int po;//variavel para o menu 8.
    int notainvalida;//Variavel de controle para o menu 3.
    int menor[14],maior[14];//Variaveis para descartar maior e menor nota.
    float vetnotas[13];//Variavel para criacao da media geral.
    float *mediageral;//Media Geral das notas decada escola.
    float mjuri[14];//Variavel de controle para o menu 3.
    float notabateria[5];//Variavel de controle para o menu 3.
    float notasambaenr[5];//Variavel de controle para o menu 3.
    float notaharmonia[5];//Variavel de controle para o menu 3.
    float notaevol[5];//Variavel de controle para o menu 3.
    float notaenr[5];//Variavel de controle para o menu 3.
    float notaconjunto[5];//Variavel de controle para o menu 3.
    float notaaleade[5];//Variavel de controle para o menu 3.
    float notafantasias[5];//Variavel de controle para o menu 3.
    float notacomfrente[5];//Variavel de controle para o menu 3.
    float notamsalapband[5];//Variavel de controle para o menu 3.
    float notaanim[5];//Variavel de controle para o menu 3.
    float notadedi[5];//Variavel de controle para o menu 3.
    float notaorg[5];//Variavel de controle para o menu 3.
    float ngeral[5];//Variavel de controle para o menu 3.
    for (z=0;z>=0;z++)//repedicao infinita ate sairem do menu.
    {
        menu=0;    
        printf ("\n\n\nEscolha a opcao:\n1-Cadastrar escola.\n2-Buscar e exibir dados da escola.\n3-Votar e calcular a nota de cada escola.\n4-Todas as escolas cadastradas e seu desempenho.\n5-Escola Campea e Vice Campea.\n6-Escolas rebaixadas.\n7-Gravar em um disco o cadastro das escolas de samba.\n8-Carregar a partir de um arquivo no disco o cadastro das escolas de samba.\n9-Encerrar Programa.\n");//Os primeiros 3 \n existem pela organizacao do programa.
        scanf ("%d", &menu);
        getchar();//Necessario para nao ignorar o proximo gets.
        if (menu==1)//Cadastrar escola.
        {
            for (a=0;a>=0;a++)//repeticao infinita ate o usuario sair desse menu.
            {
                if (numescola==0)
                {
                    printf ("Quantas escolas deseja cadastrar:\n");
                    scanf ("%d", &numescola);
                    e=(Escola*)malloc(numescola*sizeof(Escola));
                    if (e==NULL)
                    {
                        printf ("Falha na alocacao.\n");
                        exit(1);
                    }
                    mediageral=(float*)malloc(numescola*sizeof(float));//variavel de notas da escola, tamanho igual ao do vetor de escolas.
                }
                o=0; 
                sn=0;
                printf ("Qual escola deseja cadastrar?(1-Primeira, 2-Segunda, 3-Terceira...)\n");
                scanf("%d", &o);
                if (o<1||o>numescola)
                {
                    printf("Opcao invalida.\n");
                    break;
                }                 
                else
                { 
                    o=o-1;
                    getchar();//Necessario para o funcionamento do proximo gets
                    printf ("Digite o nome da escola:\n");
                    gets (e[o].nome);
                    teste=tamanho(e[o].nome);
                    if(teste==1)
                    {
                        printf ("O nome da escola e muito curto.\n");
                        break;
                    }                         
                    printf ("Digite o nome do responsavel pela escola:\n");
                    gets (e[o].resp);
                    printf ("Deseja cadastrar outra escola?\n1=Sim, 2=Nao\n");
                    scanf ("%d", &sn);
                    getchar();
                    if (sn==2)
                    {
                        break;
                    }
                }    
            }
        }
        if (menu==2)
        { 
            for (w=0;w>=0;w++)//repeticao infinita ate sair do menu;
            {
                printf ("Digite o nome da escola:\n");
                gets(menue);
                buscador=procura(menue, e, numescola);
                if (buscador==-1)
                {
                    printf ("\n\nO nome da escola é inválido ou não está cadastrado.\n\n");
                    break;
                }
                buscanome=procura(menue, e, numescola);  
                printf("Escola %s.\nResponsavel: %s.\n", e[buscanome].nome, e[buscanome].resp);
                printf("Notas por jurado:\n");
                for(f=0;f<5;f++)
                {
                    printf("Notas do jurado %s para a escola %s.\n\n\n", e[buscanome].j[f].nome, e[buscanome].nome);
                    printf ("Bateria: %f\n", e[buscanome].j[f].n.bater);
                    printf ("Samba-Enredo: %f\n", e[buscanome].j[f].n.sambaenr);
                    printf ("Harmonia: %f\n", e[buscanome].j[f].n.harmonia);
                    printf ("Evolucao: %f\n", e[buscanome].j[f].n.evol);
                    printf ("Enredo: %f\n", e[buscanome].j[f].n.enr);
                    printf ("Conjunto: %f\n", e[buscanome].j[f].n.conjunto);
                    printf ("Alegorias e Aderecos: %f\n", e[buscanome].j[f].n.aleade);
                    printf ("Fantasias: %f\n", e[buscanome].j[f].n.fantasias);
                    printf ("Comissao de frente: %f\n", e[buscanome].j[f].n.comfrente);
                    printf ("Mestre-Sala e Porta-Bandeira: %f\n", e[buscanome].j[f].n.msalapband);
                    printf ("Animacao: %f\n", e[buscanome].j[f].n.anim);
                    printf ("Dedicacao: %f\n", e[buscanome].j[f].n.dedi);
                    printf ("Organizacao: %f.\n", e[buscanome].j[f].n.org);
                    printf ("Nota Geral: %f\n\n\n", e[buscanome].j[f].n.notageral);
                }                      
                printf ("Deseja buscar por outra escola?\n1=Sim, 2=Nao\n");
                scanf ("%d", &d);
                getchar();
                if (d==2)
                {
                    break;
                }
            }
        }
        if (menu==3)//Calcular a nota de cada escola.
        {
            for (b=0;b>=0;b++)
            {
                v=0;
                c=0;
                printf ("Qual escola deseja avaliar?(1-Primeira, 2-Segunda, 3-Terceira...)\n");
                scanf("%d", &c);
                if (c<1||c>numescola)
                {
                    printf("Opcao invalida.\n");
                    break;
                }
                else
                {                
                    getchar();//necessario para o funcionamento do proximo gets.
                    c=c-1;
                    printf ("\n\nA escola %s foi escolhida para ser avaliada.\n", e[c].nome);
                    if (cadastrojurados==0)
                    {
                        for (k=0;k<5;k++)
                        {
                            printf ("Digite o nome do Jurado %d:\n", k+1);
                            gets (e[c].j[k].nome);
                            cadastrojurados=1;
                        }
                    }             
                    for (k=0;k<5;k++)
                    {
                        if (c>=1)
                        {
                            strcpy (e[c].j[k].nome, e[c-1].j[k].nome);
                        }
                        printf ("\n\nNotas do jurado %s para a escola %s.\n", e[c].j[k].nome,e[c].nome);
                        printf ("Digite as notas:\n");
                        for (f=0;f>=0;f++)//Repeticao infinita ate a nota digitada estar no intervalo permitido.
                        {
                            printf ("Bateria:\n");
                            scanf ("%f", &e[c].j[k].n.bater);
                            if (e[c].j[k].n.bater<7||e[c].j[k].n.bater>10)
                            {
                                printf ("Bateria: nota invalida, deve estar no intervalo de 7 a 10\n");
                            }
                            else
                            {
                                break;
                            }
                        }
                        for (f=0;f>=0;f++)//Repeticao infinita ate a nota digitada estar no intervalo permitido.
                        {
                            printf ("Samba-Enredo:\n");
                            scanf ("%f", &e[c].j[k].n.sambaenr);
                            if (e[c].j[k].n.sambaenr<7||e[c].j[k].n.sambaenr>10)
                            {
                                printf ("Samba-Enredo: nota invalida, deve estar no intervalo de 7 a 10\n");
                            }
                            else
                            {
                                break;
                            }
                        }
                        for (f=0;f>=0;f++)//Repeticao infinita ate a nota digitada estar no intervalo permitido.
                        {
                            printf ("Harmonia:\n");
                            scanf ("%f", &e[c].j[k].n.harmonia);
                            if (e[c].j[k].n.harmonia<7||e[c].j[k].n.harmonia>10)
                            {
                                printf ("Harmonia: nota invalida, deve estar no intervalo de 7 a 10\n");
                            }
                            else
                            {
                                break;
                            }
                        }
                        for (f=0;f>=0;f++)//Repeticao infinita ate a nota digitada estar no intervalo permitido.
                        {
                            printf ("Evolucao:\n");
                            scanf ("%f", &e[c].j[k].n.evol);
                            if (e[c].j[k].n.evol<7||e[c].j[k].n.evol>10)
                            {
                                printf ("Evolucao: nota invalida, deve estar no intervalo de 7 a 10\n");
                            }
                            else
                            {
                                break;
                            }
                        }
                        for (f=0;f>=0;f++)//Repeticao infinita ate a nota digitada estar no intervalo permitido.
                        {
                            printf ("Enredo:\n");
                            scanf ("%f", &e[c].j[k].n.enr);
                            if (e[c].j[k].n.enr<7||e[c].j[k].n.enr>10)
                            {
                                printf ("Enredo: nota invalida, deve estar no intervalo de 7 a 10\n");
                            }
                            else
                            {
                                break;
                            }
                        }
                        for (f=0;f>=0;f++)//Repeticao infinita ate a nota digitada estar no intervalo permitido.
                        {
                            printf ("Conjunto:\n");
                            scanf ("%f", &e[c].j[k].n.conjunto);
                            if (e[c].j[k].n.conjunto<7||e[c].j[k].n.conjunto>10)
                            {
                                printf ("Conjunto: nota invalida, deve estar no intervalo de 7 a 10\n");
                            }
                            else
                            {
                                break;
                            }
                        }
                        for (f=0;f>=0;f++)//Repeticao infinita ate a nota digitada estar no intervalo permitido.
                        {
                            printf ("Alegorias e Aderecos:\n");
                            scanf ("%f", &e[c].j[k].n.aleade);
                            if (e[c].j[k].n.aleade<7||e[c].j[k].n.aleade>10)
                            {
                                printf ("Alegorias e Aderecos: nota invalida, deve estar no intervalo de 7 a 10\n");
                            }
                            else
                            {
                                break;
                            }
                        }
                        for (f=0;f>=0;f++)//Repeticao infinita ate a nota digitada estar no intervalo permitido.
                        {
                            printf ("Fantasias:\n");
                            scanf ("%f", &e[c].j[k].n.fantasias);
                            if (e[c].j[k].n.fantasias<7||e[c].j[k].n.fantasias>10)
                            {
                                printf ("Fantasias: nota invalida, deve estar no intervalo de 7 a 10\n");
                            }
                            else
                            {
                                break;
                            }
                        }
                        for (f=0;f>=0;f++)//Repeticao infinita ate a nota digitada estar no intervalo permitido.
                        {
                            printf ("Comissao de frente:\n");
                            scanf ("%f", &e[c].j[k].n.comfrente);
                            if (e[c].j[k].n.comfrente<7||e[c].j[k].n.comfrente>10)
                            {
                                printf ("Comissao de frente: nota invalida, deve estar no intervalo de 7 a 10\n");
                            }
                            else
                            {
                                break;
                            }
                        }
                        for (f=0;f>=0;f++)//Repeticao infinita ate a nota digitada estar no intervalo permitido.
                        {
                            printf ("Mestre-Sala e Porta-Bandeira:\n");
                            scanf ("%f", &e[c].j[k].n.msalapband);
                            if (e[c].j[k].n.msalapband<7||e[c].j[k].n.msalapband>10)
                            {
                                printf ("Mestre-Sala e Porta-Bandeira: nota invalida, deve estar no intervalo de 7 a 10\n");
                            }
                            else
                            {
                                break;
                            }
                        }
                        for (f=0;f>=0;f++)//Repeticao infinita ate a nota digitada estar no intervalo permitido.
                        {
                            printf ("Animacao:\n");
                            scanf ("%f", &e[c].j[k].n.anim);
                            if (e[c].j[k].n.anim<7||e[c].j[k].n.anim>10)
                            {
                                printf ("Animacao: nota invalida, deve estar no intervalo de 7 a 10\n");
                            }
                            else
                            {
                                break;
                            }
                        }
                        for (f=0;f>=0;f++)//Repeticao infinita ate a nota digitada estar no intervalo permitido.
                        {
                            printf ("Dedicacao:\n");
                            scanf ("%f", &e[c].j[k].n.dedi);
                            if (e[c].j[k].n.dedi<7||e[c].j[k].n.dedi>10)
                            {
                                printf ("Dedicacao: nota invalida, deve estar no intervalo de 7 a 10\n");    
                            }
                            else
                            {
                                break;
                            }
                        }
                        for (f=0;f>=0;f++)//Repeticao infinita ate a nota digitada estar no intervalo permitido.
                        {
                            printf ("Organizacao:\n");
                            scanf ("%f", &e[c].j[k].n.org);
                            if (e[c].j[k].n.org<7||e[c].j[k].n.org>10)
                            {
                                printf ("Organizacao: nota invalida, deve estar no intervalo de 7 a 10\n");
                            }
                            else
                            {
                                break;
                            }
                        }
                        getchar();//Necessario para o funcionamento do proximo gets.
                        vetnotas[0]=e[c].j[k].n.bater;//vetor usado para funcao somatorio;
                        vetnotas[1]=e[c].j[k].n.sambaenr;//vetor usado para funcao somatorio;
                        vetnotas[2]=e[c].j[k].n.harmonia;//vetor usado para funcao somatorio;
                        vetnotas[3]=e[c].j[k].n.evol;//vetor usado para funcao somatorio;
                        vetnotas[4]=e[c].j[k].n.enr;//vetor usado para funcao somatorio;
                        vetnotas[5]=e[c].j[k].n.conjunto;//vetor usado para funcao somatorio;
                        vetnotas[6]=e[c].j[k].n.aleade;//vetor usado para funcao somatorio;
                        vetnotas[7]=e[c].j[k].n.fantasias;//vetor usado para funcao somatorio;
                        vetnotas[8]=e[c].j[k].n.comfrente;//vetor usado para funcao somatorio;
                        vetnotas[9]=e[c].j[k].n.msalapband;//vetor usado para funcao somatorio;
                        vetnotas[10]=e[c].j[k].n.anim;//vetor usado para funcao somatorio;
                        vetnotas[11]=e[c].j[k].n.dedi;//vetor usado para funcao somatorio;
                        vetnotas[12]=e[c].j[k].n.org;//vetor usado para funcao somatorio;
                        e[c].j[k].n.notageral=somatorio(vetnotas, 12)/13; 
                        printf ("\n\nAs notas foram:\n");
                        printf ("Bateria: %f\n", e[c].j[k].n.bater);
                        printf ("Samba-Enredo: %f\n", e[c].j[k].n.sambaenr);
                        printf ("Harmonia: %f\n", e[c].j[k].n.harmonia);
                        printf ("Evolucao: %f\n", e[c].j[k].n.evol);
                        printf ("Enredo: %f\n", e[c].j[k].n.enr);
                        printf ("Conjunto: %f\n", e[c].j[k].n.conjunto);
                        printf ("Alegorias e Aderecos: %f\n", e[c].j[k].n.aleade);
                        printf ("Fantasias: %f\n", e[c].j[k].n.fantasias);
                        printf ("Comissao de frente: %f\n", e[c].j[k].n.comfrente);
                        printf ("Mestre-Sala e Porta-Bandeira: %f\n", e[c].j[k].n.msalapband);
                        printf ("Animacao: %f\n", e[c].j[k].n.anim);
                        printf ("Dedicacao: %f\n", e[c].j[k].n.dedi);
                        printf ("Organizacao: %f.\n", e[c].j[k].n.org);
                        printf ("Nota Geral: %f\n", e[c].j[k].n.notageral);
                        
                    }
                    for (y=0;y<5;y++)
                    {
                        notabateria[y]=e[c].j[y].n.bater;//vetor usado para funcao descartamaior e descartamenor.
                        notasambaenr[y]=e[c].j[y].n.sambaenr;//vetor usado para funcao descartamaior e descartamenor.
                        notaharmonia[y]=e[c].j[y].n.harmonia;//vetor usado para funcao descartamaior e descartamenor.
                        notaevol[y]=e[c].j[y].n.evol;//vetor usado para funcao descartamaior e descartamenor.
                        notaenr[y]=e[c].j[y].n.enr;//vetor usado para funcao descartamaior e descartamenor.
                        notaconjunto[y]=e[c].j[y].n.conjunto;//vetor usado para funcao descartamaior e descartamenor.
                        notaaleade[y]=e[c].j[y].n.aleade;//vetor usado para funcao descartamaior e descartamenor.
                        notafantasias[y]=e[c].j[y].n.fantasias;//vetor usado para funcao descartamaior e descartamenor.
                        notacomfrente[y]=e[c].j[y].n.comfrente;//vetor usado para funcao descartamaior e descartamenor.
                        notamsalapband[y]=e[c].j[y].n.msalapband;//vetor usado para funcao descartamaior e descartamenor.
                        notaanim[y]=e[c].j[y].n.anim;//vetor usado para funcao descartamaior e descartamenor.
                        notadedi[y]=e[c].j[y].n.dedi;//vetor usado para funcao descartamaior e descartamenor.
                        notaorg[y]=e[c].j[y].n.org;//vetor usado para funcao descartamaior e descartamenor.
                        ngeral[y]=e[c].j[y].n.notageral;//vetor usado para funcao descartamaior e descartamenor.
                    }
                    maior[0]=descartamaior(notabateria);//recebe a posicao maior desse quesito;
                    maior[1]=descartamaior(notasambaenr);//recebe a posicao maior desse quesito;
                    maior[2]=descartamaior(notaharmonia);//recebe a posicao maior desse quesito;
                    maior[3]=descartamaior(notaevol);//recebe a posicao maior desse quesito;
                    maior[4]=descartamaior(notaenr);//recebe a posicao maior desse quesito;
                    maior[5]=descartamaior(notaconjunto);//recebe a posicao maior desse quesito;
                    maior[6]=descartamaior(notaaleade);//recebe a posicao maior desse quesito;
                    maior[7]=descartamaior(notafantasias);//recebe a posicao maior desse quesito;
                    maior[8]=descartamaior(notacomfrente);//recebe a posicao maior desse quesito;
                    maior[9]=descartamaior(notamsalapband);//recebe a posicao maior desse quesito;
                    maior[10]=descartamaior(notaanim);//recebe a posicao maior desse quesito;
                    maior[11]=descartamaior(notadedi);//recebe a posicao maior desse quesito;
                    maior[12]=descartamaior(notaorg);//recebe a posicao maior desse quesito;
                    maior[13]=descartamaior(ngeral);//recebe a posicao maior desse quesito;
                    menor[0]=descartamenor(notabateria);//recebe a posicao menor desse quesito;
                    menor[1]=descartamenor(notasambaenr);//recebe a posicao menor desse quesito;
                    menor[2]=descartamenor(notaharmonia);//recebe a posicao menor desse quesito;
                    menor[3]=descartamenor(notaevol);//recebe a posicao menor desse quesito;
                    menor[4]=descartamenor(notaenr);//recebe a posicao menor desse quesito;
                    menor[5]=descartamenor(notaconjunto);//recebe a posicao menor desse quesito;
                    menor[6]=descartamenor(notaaleade);//recebe a posicao menor desse quesito;
                    menor[7]=descartamenor(notafantasias);//recebe a posicao menor desse quesito;
                    menor[8]=descartamenor(notacomfrente);//recebe a posicao menor desse quesito;
                    menor[9]=descartamenor(notamsalapband);//recebe a posicao menor desse quesito;
                    menor[10]=descartamenor(notaanim);//recebe a posicao menor desse quesito;
                    menor[11]=descartamenor(notadedi);//recebe a posicao menor desse quesito;
                    menor[12]=descartamenor(notaorg);//recebe a posicao menor desse quesito;
                    menor[13]=descartamenor(ngeral);//recebe a posicao menor desse quesito;
                    mjuri[0]=calculamedia(notabateria, 4, maior[0], menor[0]);//recebe a media desse quesito.
                    mjuri[1]=calculamedia(notasambaenr, 4, maior[1], menor[1]);//recebe a media desse quesito.
                    mjuri[2]=calculamedia(notaharmonia, 4, maior[2], menor[2]);//recebe a media desse quesito.
                    mjuri[3]=calculamedia(notaevol, 4, maior[3], menor[3]);//recebe a media desse quesito.
                    mjuri[4]=calculamedia(notaenr, 4, maior[4], menor[4]);//recebe a media desse quesito.
                    mjuri[5]=calculamedia(notaconjunto, 4, maior[5], menor[5]);//recebe a media desse quesito.
                    mjuri[6]=calculamedia(notaaleade, 4, maior[6], menor[6]);//recebe a media desse quesito.
                    mjuri[7]=calculamedia(notafantasias, 4, maior[7], menor[7]);//recebe a media desse quesito.
                    mjuri[8]=calculamedia(notacomfrente, 4, maior[8], menor[8]);//recebe a media desse quesito.
                    mjuri[9]=calculamedia(notamsalapband, 4, maior[9], menor[9]);//recebe a media desse quesito.
                    mjuri[10]=calculamedia(notaanim, 4, maior[10], menor[10]);//recebe a media desse quesito.
                    mjuri[11]=calculamedia(notadedi, 4, maior[11], menor[11]);//recebe a media desse quesito.
                    mjuri[12]=calculamedia(notaorg, 4, maior[12], menor[12]);//recebe a media desse quesito.
                    mjuri[13]=calculamedia(ngeral, 4, maior[13], menor[13]);//recebe a media desse quesito.
                    printf ("\n\nMedia das notas:\n\n");
                    printf ("Escola %s:\n", e[c].nome);
                    printf ("Media bateria: %f\n", mjuri[0]);
                    printf ("Media Samba-Enredo: %f\n", mjuri[1]);
                    printf ("Media Harmonia: %f\n", mjuri[2]);
                    printf ("Media Evolucao: %f\n", mjuri[3]);
                    printf ("Media Enredo: %f\n", mjuri[4]);
                    printf ("Media Conjunto: %f\n", mjuri[5]);
                    printf ("Media Alegorias e Aderecos: %f\n", mjuri[6]);
                    printf ("Media Fantasias: %f\n", mjuri[7]);
                    printf ("Media Comissao de frente: %f\n", mjuri[8]);
                    printf ("Media Mestre-Sala e Porta-Bandeira: %f\n", mjuri[9]);
                    printf ("Media Animacao: %f\n", mjuri[10]);
                    printf ("Media Dedicacao: %f\n", mjuri[11]);
                    printf ("Media Organizacao: %f\n", mjuri[12]);
                    printf ("Media Geral: %f\n", mjuri[13]);
                    mediageral[c]=mjuri[13];//Media Geral da escola usada na classificacao da escola. (menu de lideres e rebaixadas)
                    printf ("Deseja avaliar outra escola?\n1=Sim, 2=Nao\n");
                    scanf ("%d", &v);
                    getchar();
                    if (v==2)
                    {
                        break;
                    }    
                }
            }
        }
        if (menu==4)//Todas as escolas cadastradas e seu desempenho.
        {
            for (g=0;g<numescola;g++)
            {
                printf("Escola %s.\nResponsavel: %s.\n", e[g].nome, e[g].resp);
                printf("Notas por jurado:\n\n\n");
                for(h=0;h<5;h++)
                {
                    printf("Notas do jurado %s.\n\n\n", e[g].j[h].nome);
                    printf ("Bateria: %f\n", e[g].j[h].n.bater);
                    printf ("Samba-Enredo: %f\n", e[g].j[h].n.sambaenr);
                    printf ("Harmonia: %f\n", e[g].j[h].n.harmonia);
                    printf ("Evolucao: %f\n", e[g].j[h].n.evol);
                    printf ("Enredo: %f\n", e[g].j[h].n.enr);
                    printf ("Conjunto: %f\n", e[g].j[h].n.conjunto);
                    printf ("Alegorias e Aderecos: %f\n", e[g].j[h].n.aleade);
                    printf ("Fantasias: %f\n", e[g].j[h].n.fantasias);
                    printf ("Comissao de frente: %f\n", e[g].j[h].n.comfrente);
                    printf ("Mestre-Sala e Porta-Bandeira: %f\n", e[g].j[h].n.msalapband);
                    printf ("Animacao: %f\n", e[g].j[h].n.anim);
                    printf ("Dedicacao: %f\n", e[g].j[h].n.dedi);
                    printf ("Organizacao: %f.\n", e[g].j[h].n.org);
                    printf ("Nota Geral: %f\n\n\n", e[g].j[h].n.notageral);
                }
                printf ("Média da escola %s: %f.\n", e[g].nome, mediageral[g]);
            }
        }
        if (menu==5)//Escolas Campea e Vice-Campea.
        {
            lideres(mediageral, e, numescola);
            }
        if (menu==6)//Escolas Rebaixadas.
        {
            rebaixadas(mediageral, e, numescola);
        }
        if (menu==7)//Gravar em um arquivo no disco o cadastro das escolas de samba.
        {
            FILE *f;
            f=fopen("gravar.txt", "w");
            if (f==NULL)
            {
                printf ("\n\nErro na abertura!\n\n");
                exit(1);
            }
            else
            {
                printf ("Arquivo aberto corretamente.\n");
            }
            fprintf(f,"%d\n", numescola);
            for (g=0;g<numescola;g++)
            {
                fprintf (f,"%d\n", g+1);
                fprintf(f,"%s\n", e[g].nome); 
                fprintf (f,"%s\n", e[g].resp);
            }
            fclose(f);
        }
        if (menu==8)//Carregar a partir de um arquivo no disco o cadastro das escolas de samba.
        {
            FILE *gf;
            gf=fopen("gravar.txt", "r");
            if (gf==NULL)
            {
                printf ("\n\nErro na abertura!\n\n");
                exit(1);
            }
            else
            {
                printf ("Arquivo aberto corretamente.\n");
            }
            fscanf (gf, "%d", &numescola);//Leitura do numero de escolas.
            e=(Escola*)malloc(numescola*sizeof(Escola));
            if (e==NULL)
            {
                printf ("Falha na alocacao.\n");
                exit(1);
            }
            for (po=0;po<numescola;po++)
            {   
                fscanf (gf, "%d\n", &texto);
                fgets(e[po].nome, 51, gf);//Leitura do nome da escola.
                i=0;
                while(e[po].nome[i]!= '\0')//usado para retirar o /n do fgets.
                {
                    if (e[po].nome[i]=='\n')
                    {
                        e[po].nome[i]= '\0';
                    }
                    i++;
                }
                fgets(e[po].resp, 51, gf);//Leitura do responsavel pela escola.
                i=0;
                while(e[po].resp[i]!= '\0')//usado para retirar o /n do fgets.
                {
                    if (e[po].resp[i]=='\n')
                    {
                        e[po].resp[i]= '\0';
                    }
                    i++;
                }
            }
            fclose(gf);
        }
        if (menu==9)//Sair do programa.
        {
            printf ("O programa sera encerrado.\n");
            break;
        }
        if (menu>9||menu<1)
        {
            printf("Opcao invalida.\n");
        }
    }
    free(e);
    free(mediageral);
    return 0;
}	
