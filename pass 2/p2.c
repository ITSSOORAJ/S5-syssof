#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int findAddress(int op){
	FILE *INTERMEDIATE;
	char opcode[22],operand[33],label[43],address[10];
	int finalAddress=0,count=0,start;
	INTERMEDIATE=fopen("output.txt","r");
	fscanf(INTERMEDIATE,"%s%s%s",label,opcode,operand);
	start=atoi(operand);
	while(strcmp(opcode,"END")!=0){
		fscanf(INTERMEDIATE,"%s%s%s%s",address,label,opcode,operand);
		
		if( strcmp(opcode,"RESW")==0 )
			count=count+3*atoi(operand);
		if( strcmp(opcode,"RESB")==0 )
			count=count+atoi(operand);			
		finalAddress=atoi(address);
	}
	
	fclose(INTERMEDIATE);
	if(op==0)
		return finalAddress;
	 else if(op==1)
		{
	return finalAddress-start-count;
		}
}

//FUNCTIUON TO FIND THE ADDRESS OF LABEL IN SYMTAB
int findInSYMTAB(char findLabel[]){
	FILE *SYMTAB;
	char label[30],addr[30];
	SYMTAB=fopen("symbol.txt","r");
	fscanf(SYMTAB,"%s%s",label,addr);
		

	while(1){
		if(feof(SYMTAB)){
			fclose(SYMTAB);
			break;
	
			}
	
		if(strcmp(findLabel,label)==0){
			fclose(SYMTAB);
			return atoi(addr);
		}
		fscanf(SYMTAB,"%s%s",label,addr);
	}
}

int getMnemonicCode(char mnemonic[]){
		if(strcmp(mnemonic,"LDA")==0)
			return 33;
		else if(strcmp(mnemonic,"STA")==0)
			return 44;
		else if(strcmp(mnemonic,"LDCH")==0)
			return 53;
		else if(strcmp(mnemonic,"STCH")==0)
			return 57;
		else
			return -1;
}

void main(){
	FILE *INTERMEDIATE,*SYMTAB,*FINAL,*OBJ;
	int finalAddress=0,length,i,startAddr;
	char opcode[22],operand[33],label[43],address[10];
	
	SYMTAB=fopen("symbol.txt","r");
	FINAL=fopen("final.txt","w");
	OBJ=fopen("obj.txt","w");
	
	finalAddress=findAddress(0); 
	
	INTERMEDIATE=fopen("output.txt","r");
	fscanf(INTERMEDIATE,"%s%s%s",label,opcode,operand);
	
	startAddr=atoi(operand);
	if( strcmp(opcode,"START")==0){
		fprintf(FINAL,"%s\t%s\t%s\t\n",label,opcode,operand);
		length=finalAddress-startAddr;
		
		fprintf(OBJ,"H^%s^00%s^00%d\n",label,operand,length);
		fscanf(INTERMEDIATE,"%s%s%s%s",address,label,opcode,operand);
		fprintf(OBJ,"T^%06d^%d^",atoi(address),findAddress(1));

	}
	
	while(strcmp(opcode,"END")!=0){
	
		if(strcmp(label,"**")==0 ){
			fprintf(OBJ,"%d%d^",getMnemonicCode(opcode),findInSYMTAB(operand));
			fprintf(FINAL,"%s\t%s\t%s\t%s\t%d%d\n",address,label,opcode,operand,getMnemonicCode(opcode),findInSYMTAB(operand));
			fscanf(INTERMEDIATE,"%s%s%s%s",address,label,opcode,operand);
		}	
		else if(strcmp(opcode,"BYTE")==0){
		
			fprintf(FINAL,"%s\t%s\t%s\t%s",address,label,opcode,operand);
			for(i=2;i<(strlen(operand)-1);i++){
				fprintf(OBJ,"%x",operand[i]);
				fprintf(FINAL,"\t%x",operand[i]);
				
				
			}	
		fprintf(FINAL,"\n");	
		fscanf(INTERMEDIATE,"%s%s%s%s",address,label,opcode,operand);		
					
		}
			
		else if(strcmp(opcode,"WORD")==0){
			fprintf(OBJ,"^%06x^",atoi(operand));
			fprintf(FINAL,"%s\t%s\t%s\t%s\t%06x\n",address,label,opcode,operand,atoi(operand));		
			fscanf(INTERMEDIATE,"%s%s%s%s",address,label,opcode,operand);		
		}	
		else{
			fscanf(INTERMEDIATE,"%s%s%s%s",address,label,opcode,operand);
		}
			
	}
	fprintf(FINAL,"%s\t%s\t%s\t%s\n",address,label,opcode,operand);	
	fprintf(OBJ,"\nE^%06d\n",startAddr); 
	
	
}
