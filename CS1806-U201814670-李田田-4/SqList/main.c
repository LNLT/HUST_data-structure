/* Linear Table On Sequence Structure */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

/*---------page 10 on textbook ---------*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2
#define NO -1

typedef int status;
typedef int ElemType; //����Ԫ�����Ͷ���

/*-------page 22 on textbook -------*/
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef struct{  //˳���˳��ṹ���Ķ���
	ElemType *elem;
	int length;
	int listsize;
}SqList;

/*-----page 19 on textbook ---------*/
status InitList(SqList *L);//����
status DestroyList(SqList *L);//����
status ClearList(SqList *L);//���
status ListEmpty(SqList L);//�жϿձ�
status ListLength(SqList L);//���
status GetElem(SqList L,int i,ElemType *e);//���Ԫ��
int LocateElem(SqList L,ElemType e); //����Ԫ��
status PriorElem(SqList L,ElemType cur,ElemType *pre_e);//���ǰ��
status NextElem(SqList L,ElemType cur,ElemType *next_e);//��ú���
status ListInsert(SqList *L,int i,ElemType e);//����
status ListDelete(SqList *L,int i,ElemType *e);//ɾ��
status ListTrabverse(SqList L);  //����
status Wirte(SqList L);//д���ļ�
status Read(SqList *L);//��ȡ�ļ�

/*--------------------------------------------*/
int main(void){
    SqList M[100];  SqList L;//�����������
    int t,i;
    ElemType p,cur;
    ElemType *pre_e,*next_e,*e;
    t=1;
    while(t){
        int op=1;
        printf("  ��������ĸ����Ա���в�����1-99��������0�˳���\n");
        scanf("%d",&t);//������Ա��ʵ��
        if(t==0)
            break;//0ʱ�˳�
        else {
            if(t>99||t<0){
                printf("ѡ��ʧ�ܣ�\n");
                getchar();
            }
            else {
                M[t].elem=NULL;
                L=M[t];
                while(op){
                    system("cls");	//printf("\n\n");
                    printf("  Menu for Linear Table On Sequence Structure \n");
                    printf("-----------------------------------------------\n");
                    printf("   1. InitList        8. PriorElem \n");
                    printf("   2. DestroyList     9. NextElem\n");
                    printf("   3. ClearList      10. ListInsert\n");
                    printf("   4. ListEmpty      11. ListDelete\n");
                    printf("   5. ListLength     12. ListTrabverse\n");
                    printf("   6. GetElem        13. Write\n");
                    printf("   7. LocateElem     14. Read\n");
                    printf("   0. Exit\n");
                    printf("-----------------------------------------------\n");
                    printf("   ��ѡ����Ĳ���[0~14]:\n");
                    scanf("%d",&op);
                    switch(op){
                       case 1:
                         if(InitList(&L)==OK)
                            printf("���Ա����ɹ���\n");
                         else
                            printf("���Ա���ʧ�ܣ�\n");
                         getchar();getchar();
                         break;
                       case 2:
                         if(DestroyList(&L)==OK)
                            printf("���Ա����ٳɹ���\n");
                         else
                            printf("���Ա�����ʧ�ܣ�\n");
                         getchar();getchar();
                         break;
                       case 3:
                         if(L.elem!=NULL){
                            ClearList(&L);
                            printf("������Ա�\n");
                         }
                         else
                            printf("���Ա����ڣ�\n");
                         getchar();getchar();
                         break;
                       case 4:
                         if(L.elem!=NULL){
                             if(ListEmpty(L)==TRUE)
                                printf("���Ա�Ϊ�գ�\n");
                             else
                                printf("���Ա�Ϊ�գ�\n");
                         }
                         else
                            printf("���Ա����ڣ�\n");
                         getchar();getchar();
                         break;
                       case 5:
                         if(L.elem!=NULL){
                             ListLength(L);
                             printf("���Ա�ĳ���Ϊ%d��\n",L.length);
                         }
                         else
                            printf("���Ա����ڣ�\n");
                         getchar();getchar();
                         break;
                       case 6:
                         if(L.elem!=NULL){
                             printf("��������Ҫ���Ԫ�ص�λ�ã�\n");
                             scanf("%d",&i);
                             if(GetElem(L,i,&e)!=ERROR){
                                printf("��%d��Ԫ��Ϊ%d��\n",i,e);
                             }
                             else
                                printf("��λ�ò�����\n");
                         }
                         else
                            printf("���Ա����ڣ�\n");
                         getchar();getchar();
                         break;
                       case 7:
                         if(L.elem!=NULL){
                             printf("��������Ҫ���ҵ�Ԫ�أ�\n");
                             scanf("%d",&p);
                             if(LocateElem(L,p))
                                printf("��%d��Ԫ�����Ԫ����ͬ\n",LocateElem(L,p));
                             else
                                printf("��������ͬ��Ԫ��\n");
                         }
                         else
                            printf("���Ա����ڣ�\n");
                         getchar();getchar();
                         break;
                       case 8:
                         if(L.elem!=NULL){
                             printf("��������Ҫ�����ǰ����Ԫ�أ�\n");
                             scanf("%d",&cur);
                             if(PriorElem(L,cur,&pre_e))
                                printf("��Ԫ�ص�ǰ��Ϊ%d",pre_e);
                             else
                                printf("����ʧ�ܣ�\n");
                         }
                         else
                            printf("���Ա����ڣ�\n");
                         getchar();getchar();
                         break;
                       case 9:
                         if(L.elem!=NULL){
                             printf("��������Ҫ������̵�Ԫ�أ�\n");
                             scanf("%d",&cur);
                             if(NextElem(L,cur,&next_e))
                                printf("��Ԫ�صĺ��Ϊ%d",next_e);
                             else
                                printf("����ʧ�ܣ�\n");
                         }
                         else
                            printf("���Ա����ڣ�\n");
                         getchar();getchar();
                         break;
                       case 10:
                         if(L.elem!=NULL){
                             printf("���������룺�ڵ�_��λ��֮ǰ����Ԫ��_\n");
                             scanf("%d",&i);
                             getchar();
                             scanf("%d",&p);
                             if(ListInsert(&L,i,p)==OK)
                                printf("����ɹ���\n");
                             else
                                printf("����ʧ�ܣ�\n");
                         }
                         else
                            printf("���Ա����ڣ�\n");
                         getchar();getchar();
                         break;
                       case 11:
                         if(L.elem!=NULL){
                             printf("���������룺ɾ����_��λ�õ�Ԫ��\n");
                             scanf("%d",&i);
                             if(ListDelete(&L,i,&e)==OK)
                             printf("ɾ���ɹ���\n");
                             else
                                printf("ɾ��ʧ�ܣ�\n");
                         }
                         else
                            printf("���Ա����ڣ�\n");
                         getchar();getchar();
                         break;
                       case 12:
                         if(L.elem!=NULL){
                             if(ListTrabverse(L)==0)
                                printf("���Ա��ǿձ�\n");
                         }
                         else
                            printf("���Ա����ڣ�\n");
                         getchar();getchar();
                         break;
                       case 13:
                         if(L.elem!=NULL){
                             if(Wirte(L)==OK)
                                printf("д��ɹ���\n");
                             else
                                printf("д��ʧ�ܣ�\n");
                         }
                         else
                            printf("���Ա����ڣ�\n");
                         getchar();getchar();
                         break;
                       case 14:
                         if(L.elem!=NULL){
                             if(Read(&L)==OK)
                                printf("��ȡ�ɹ���\n");
                             else
                                printf("��ȡʧ�ܣ�\n");
                         }
                         else
                            printf("���Ա����ڣ�\n");
                         getchar();getchar();
                         break;
                       case 0:
                         break;
                     }
                }//end of switch
            }
        }
    }//end of while
    printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
}//end of main()

status InitList(SqList *L){//����һ���յ�˳�����Ա�L
	L->elem = (ElemType *)malloc( LIST_INIT_SIZE * sizeof (ElemType));
	if(!L->elem)
        exit(OVERFLOW);
	L->length=0;
	L->listsize=LIST_INIT_SIZE;
	return OK;
}

status DestroyList(SqList *L){//�������Ա�L
    if(L->elem){
        free(L->elem);//�ͷ����Ա�ռ�
        L->elem=NULL;
        L->length=0;
        L->listsize=0;
        return OK;
    }
    else
        return ERROR;
}

status ClearList(SqList *L){//��L��Ϊ�ձ�
    if(L->elem!=NULL){
        L->length=0;
        return OK;
    }
    else
        printf("���Ա����ڣ�\n");
        return NO;
}

status ListEmpty(SqList L){//�ж�L�Ƿ�Ϊ��
    if(L.length==0)
        return TRUE;
    else
        return FALSE;
}

status ListLength(SqList L){//����L��Ԫ�ظ���
    return L.length;
}

status GetElem(SqList L,int i,ElemType *e){//��e���ص�i��Ԫ�ص�ֵ
    if(L.length==0||i<1||i>L.length)
        return ERROR;//˳�����Ա�Ϊ�ջ�i��ֵ���Ϸ�
    *e=L.elem[i-1];
    return OK;
}

int LocateElem(SqList L,ElemType e){//����L����e��ȵ�Ԫ�ص�λ���޷���0
    int i;
    if(L.elem!=NULL){
        for(i=0;i<=(L.length-1);i++)
            if(L.elem[i]==e)
                return ++i;
        return ERROR;
    }
} //�򻯹�

status PriorElem(SqList L,ElemType cur,ElemType *pre_e){//����curԪ�ص�ǰ��
    int i;
    i=LocateElem(L,cur);//�ҵ�cur��λ��
    if(i==1||i==ERROR)
         return ERROR;
    else{
       *pre_e=L.elem[i-2];
        return OK;
    }
}

status NextElem(SqList L,ElemType cur,ElemType *next_e){//����curԪ�صĺ��
    int i;
    i=LocateElem(L,cur);
	if(i==L.length||i==ERROR)
        return ERROR;
    else{
        *next_e=L.elem[i];
        return OK;
    }
}

status ListInsert(SqList *L,int i,ElemType e){//��˳�����Ա��е�i��Ԫ��֮ǰ�����µ�Ԫ��e��1<=i<=listlenth+1
    ElemType *newbase;
    ElemType *q,*p;
    ElemType t;
    if(i<1||(i>L->length+1))
        return ERROR;//i���Ϸ�
    if(L->length>=L->listsize){
        newbase = (ElemType *)realloc(L->elem,(L->listsize+LISTINCREMENT) * sizeof(ElemType));//���ӷ���
        if(!newbase)
            exit(OVERFLOW);//�洢����ʧ��
        L->elem=newbase;//�»�ַ
        L->listsize+=LISTINCREMENT;
    }
    q=&(L->elem[i-1]);
    for(p=&(L->elem[L->length-1]);q<=p;p--)
        *(p+1)=*p;//����λ�ü�֮���Ԫ������
    L->elem[i-1]=e;
    ++(L->length);
    return OK;
}

status ListDelete(SqList *L,int i,ElemType *e){//��˳�����Ա���ɾ����i��Ԫ�أ�����e������ֵ
    ElemType *q,*p;
    if(i<1||(i>L->length))
        return ERROR;//i���Ϸ�
    e=L->elem[i-1];//��ɾ��Ԫ��ֵ����e
    p=L->elem+L->length-1;//��pΪ��βλ��
    for(q=&(L->elem[i]);q<=p;q++)
        *(q-1)=*q;//��ɾԪ��֮���Ԫ������ǰ��
    --(L->length);
    return OK;
}
status ListTrabverse(SqList L){//������
    int i;
    printf("\n-----------all elements -----------------------\n");
    for(i=0;i<L.length;i++)
        printf("%d ",L.elem[i]);
    printf("\n------------------ end ------------------------\n");
    return L.length;
}

status Wirte(SqList L) {
    FILE  *fp=NULL;
    char filename[30];
    printf("input file name: ");
    scanf("%s",filename);
    if ((fp=fopen(filename,"wb"))==NULL){
        printf("File open error\n ");
        return FALSE;
    }
    //д�ļ��ķ���
    fwrite(L.elem,sizeof(ElemType),L.length,fp);
    //������1����д�룬������������ṹ��
    //Ҳ������д�������д��ȫ��Ԫ��,��������������
    fclose(fp);
    return OK;
}

status Read(SqList *L) {
    FILE  *fp;
    char filename[30];
    printf("input file name: ");
    scanf("%s",filename);
    //���ļ��ķ���
    L->length=0;
    if ((fp=fopen(filename,"rb"))==NULL){
        printf("File open error\n ");
        return FALSE;
    }
    while(fread(&L->elem[L->length],sizeof(ElemType),1,fp))
    L->length++;
    //������ļ��������ȡ����Ԫ�ػָ�˳������ڲ�ͬ������ṹ����ͨ����ȡ������Ԫ�ػָ��ڴ��е�����ṹ��
	fclose(fp);
    return OK;
}

