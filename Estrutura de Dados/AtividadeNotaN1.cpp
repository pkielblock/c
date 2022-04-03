/*
ADSVA3
Nome: Henrique Ernandes Rebelo - RA: 1680482112038
Nome: Pedro Henrique Sampaio Kielblock - RA: 1680482112029
*/

void contaLetras(char *p){
	int i, j, cont = 0, letra = 0;
	char letraAtual;
	char *aux;
	aux = p;
	//contagem das palavras
	for(;*aux != '\0';cont++, aux++);
	//criando vetor para auxiliar na contagem
	char palavra[cont];
	//preenchido vetor com as letras da palavra
	for(i = cont;i >= 0; aux--, i--){
		palavra[i] = *aux;
	}
	//percorre todas letras da palavra
	for(i = 0; i < cont; i++){
		letraAtual = p[i];
		letra = 0;
		// compara cada letra com toda a palavra e retorna a quantidade de letra possuida
		 for(j = i; j < cont; j++){
			if(letraAtual == palavra[j]){
				letra++;
				//define a posicao da letra do vetor em branco para nao contar mais essa letra
				palavra[j] = ' ';
			}
		 }
		 //exibe a quantidade de letras na palavra
		 if(letra != 0){
		 	printf("%c = %d ", letraAtual, letra);
		 }
	}
}

Pilha* dividePilha(Pilha *p){
	Pilha *aux, *retorno;
	float v;
	aux=pilha_cria();
	//pilha de retorno com metade dos valores da original
	retorno=pilha_cria();
	// esvazia pilha original e coloca os conteudos na aux
	while(!pilha_vazia(p)){
		pilha_push(aux, pilha_pop(p));
	}
	// inverte a pilha aux para o estado original e insere o conteudo dividido na pilha de retorno
	while(!pilha_vazia(aux)){
		//armazena o valor para dividirmos e inserirmos na nova pilha
		v = pilha_pop(aux);
		//restaura pilha original
		pilha_push(p, v);
		//aloca pilha de retorno com seus valores pela metade
		pilha_push(retorno, (v / 2));
	}
	//libera memoria da pilha aux
	pilha_libera(aux);
	//retorna pilha com valores divididos
	return retorno;
}

Fila *intercala_filas(Fila *p1, Fila *p2){
	//Cria filas auxiliares
	Fila *aux1 = fila_cria();
	Fila *aux2 = fila_cria();
	//Cria fila para retorno
	Fila *retorno = fila_cria();
	int v;
	//preenche fila aux
	while(!fila_vazia(p1)){
		fila_insere(aux1, fila_retira(p1));
	}
	//preenche fila aux
	while(!fila_vazia(p2)){
		fila_insere(aux2, fila_retira(p2));
	}
	//enquanto ao menos uma das filas tiver conteudo sera executado
	while(!fila_vazia(aux1) || !fila_vazia(aux2)){
		//caso aux1 nao estiver vazia colocara seu conteudo na fila de retorno
		if(!fila_vazia(aux1)){
			v = fila_retira(aux1);
			fila_insere(retorno, v);
			fila_insere(p1, v);
		}
		//caso aux2 nao estiver vazia colocara seu conteudo na fila de retorno intercalando com a aux1
		if(!fila_vazia(aux2)){
			v = fila_retira(aux2);
			fila_insere(retorno, v);
			fila_insere(p2, v);
		}
	}
	//libera filas auxiliares
	free(aux1);
	free(aux2);

	return retorno;
}


