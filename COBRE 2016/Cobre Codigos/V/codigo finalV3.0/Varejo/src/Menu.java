import java.util.Scanner;
public class Menu {
	public static void main(String[] args) {
		int continuar = 0;
		do{
		continuar = 0;
		ComandoBD BD = new ComandoBD();
		ConnectionFactory Con = new ConnectionFactory();
		
		Con.getConnection();
		
		
	//	BD.Comando_Alteracao("INSERT INTO Cliente (Nome) VALUES ('Júnior');");
		
		
		
	//	INSERT INTO clientes (nome, email, empresa) VALUES ('Júnior', 'junior@dominio.com', 'RL System');
		
		
		
		String Cliente = "RG, CPF, Nome, Contato";
		
		String Produtos = "Preços, Nome, Marca, Fornecedor";
		
		String Funcionarios = "Cargo, Nome, RG, CPF, Salario, Carga_horaria";
		
		String Fornecedores = "Nome, Produtos, Contato";
		
		String Senha = "Cargo, Senha";
		
		
		
			Scanner teclado = new Scanner (System.in);
		
	    String Resposta_lista_colunas = null;
		String Resposta_coluna_alterada_valor = null;
		String Resposta_coluna_condicao_valor = null;
		String Resposta_coluna_condicao = null;	
	    String Resposta_coluna_alterada = null;
		String Resposta_sql = null;	
		String Resposta_Comando = null;
		String Resposta = null;
		Login L = new Login();
		Escolha E = new Escolha();
		Alterador Alt = new Alterador();
		
		String Resposta_tabela = null;
		
		String Resposta_alteracao = null;
		
		
		System.out.println("Bem vindo ao Varejo!\n");
		
		 Resposta = L.Sequencia_Login();
		 
		 do{
			 
		 
			 continuar = 0;
			 System.out.println("\nPermissões para " + Resposta + ": " + Alt.permissoes(Resposta));
			 
			 System.out.println("\nDigite a informação para a consulta ou alteração:\n");
			 System.out.println(Alt.permissoes_Tabela(Resposta));
			 
			 Resposta_tabela = teclado.next();
			 
if(Resposta_tabela.equalsIgnoreCase("Cliente") || Resposta_tabela.equalsIgnoreCase("Produtos") || Resposta_tabela.equalsIgnoreCase("Funcionarios") ||
Resposta_tabela.equalsIgnoreCase("Senha") || Resposta_tabela.equalsIgnoreCase("Fornecedores")){
	
	continuar = 0;
	
}else{
	
	System.out.println("\n" + Resposta_tabela + " não existe. Tente novamente.");
	continuar = 1;
	
}
	
			 
if(Resposta_tabela.equalsIgnoreCase(Alt.permissoes_Tabela_logico(Resposta, "Cliente")) || Resposta_tabela.equalsIgnoreCase(Alt.permissoes_Tabela_logico(Resposta, "Produtos")) 
|| Resposta_tabela.equalsIgnoreCase(Alt.permissoes_Tabela_logico(Resposta, "Funcionarios")) || Resposta_tabela.equalsIgnoreCase(Alt.permissoes_Tabela_logico(Resposta, "Senha"))
|| Resposta_tabela.equalsIgnoreCase(Alt.permissoes_Tabela_logico(Resposta, "Fornecedores"))){
	
	
	
	
}else if(continuar == 0){
	
	System.out.println("Você não tem permissões suficientes. Tente novamente.");
	continuar = 1;
	
}

		 }while(continuar == 1);
		do{
			continuar = 0;
		 System.out.println("Como "+Resposta+" Você pode "+Alt.permissoes_alteracao(Resposta, Resposta_tabela));
		 System.out.println("Se você tem permissao escreva Alterar para alterar ou Consultar para consultar");
		 Resposta_alteracao = teclado.next();
		 
		 
			 
			 if(Alt.permissoes_alteracao(Resposta, Resposta_tabela).equalsIgnoreCase("alterar e consultar") && Resposta_alteracao.equalsIgnoreCase("Alterar")){
				 if(Resposta.equalsIgnoreCase("Administrador(a)")){
				 System.out.println("Escolha Entre os comandos UPDATE, DELETE, INSERT ou Manual");
				 Resposta_Comando = teclado.next();
				 }else{
				 System.out.println("Escolha Entre os comandos UPDATE, DELETE, INSERT");
				 Resposta_Comando = teclado.next();
				 }
                 if(Resposta_Comando.equalsIgnoreCase("UPDATE")||Resposta_Comando.equalsIgnoreCase("DELETE")||Resposta_Comando.equalsIgnoreCase("INSERT")){
					 
                	 
                	 
				 }else{
					
					 if(Resposta_Comando.equalsIgnoreCase("Manual") && Resposta.equalsIgnoreCase("Administrador(a)")){
					 
						 
					 }else{
					 System.out.println("Você digitou alguma coisa errada tente Denovo");
					 continuar = 1;
					 }
				 }
				 
				 
				 
			 }else if(Alt.permissoes_alteracao(Resposta, Resposta_tabela).equalsIgnoreCase("alterar e consultar") && Resposta_alteracao.equalsIgnoreCase("Consultar") ||
					 Alt.permissoes_alteracao(Resposta, Resposta_tabela).equalsIgnoreCase("consultar") && Resposta_alteracao.equalsIgnoreCase("Consultar")){
				 if(Resposta.equalsIgnoreCase("Administrador(a)")){
				 System.out.println("Escolha Entre o comando SELECT ou Manual");
				 Resposta_Comando = teclado.next();
				 }else{
				 System.out.println("Você escolheu SELECT");
				 Resposta_Comando = "SELECT";
				 }
				 if(Resposta_Comando.equalsIgnoreCase("SELECT")||Resposta_Comando.equalsIgnoreCase("Manual")){
					 
				 }else{
					 
					 System.out.println("Você digitou alguma coisa errada tente Denovo");
					 continuar = 1;
					 
				 }
				 
			 }else{
				 
				System.out.println("Você digitou alguma coisa errada tente Denovo");
				continuar = 1;
				 
			 }
	}while(continuar == 1);
				 
		do{
			continuar = 0;
			
			if(Resposta_Comando.equalsIgnoreCase("Manual")){
				
				System.out.println("Você selecionou manual isso significa quê você tem liberdade para escrever o comando Mysql escreva e aperte enter: ");
				System.out.println("NÃO USE ESPAÇO USE ! NO LUGAR DE CADA ESPAÇO");
				Resposta_sql = teclado.next();
				
				Resposta_sql.replaceAll("!" , " ") ;  
				
            if(Resposta.equalsIgnoreCase("Administrador")){
            	
            	if(Resposta_alteracao.equalsIgnoreCase("Alterar")){
            		
            		
            		BD.Comando_Alteracao(Resposta_sql);
            		
            		
            	}else{
            		System.out.println("escreva qual coluna você procura selecionar");
            		String Coluna = teclado.next();
            		
            		System.out.println(BD.Comando_Consulta(Resposta_sql, Coluna));
            		
            	}
            	
            	
            	
            	
            }
				
				System.out.println("Se Deseja continuar digite 0 para voltar ao começo do Menu, digite 1 para escrever outro comando Manual digite 2 para acabar o programa");
				continuar = teclado.nextInt();
				
			}
			
			
		}while(continuar == 1);
		
		
			if(Resposta_Comando.equals("Manual")){
		
	         }else{
				 
		if(Resposta_Comando.equalsIgnoreCase("INSERT")){
			
			
		if(Resposta_tabela.equalsIgnoreCase("Cliente")){
			
			
			Resposta_coluna_alterada = Cliente;
			
			
		}else if(Resposta_tabela.equalsIgnoreCase("Produtos")){
			
			
			Resposta_coluna_alterada = Produtos;
			
			
		}else if(Resposta_tabela.equalsIgnoreCase("Funcionarios")){
			
			Resposta_coluna_alterada = Funcionarios;
			
			
		}else if(Resposta_tabela.equalsIgnoreCase("Fornecedores")){
			
			Resposta_coluna_alterada = Fornecedores;
			
		}else{
			
			
			Resposta_coluna_alterada = Senha;
			
			
		}
			
		}else{
			
		
		
		Resposta_coluna_alterada = E.Coluna(Resposta_tabela, 0);
		Resposta_coluna_condicao = E.Coluna(Resposta_tabela, 1);
		
		}
		
		
		do{
			continuar = 0;
			
			if(Resposta_Comando.equalsIgnoreCase("INSERT")){
				
			System.out.println("diga os valores que serão inseridos na tabela ");
			System.out.println("escreva um valor aperte enter e escreva outro até todos os valores terem sido Preenchidos");
			System.out.println("em ordem de acordo com as colunas:");
			System.out.println(Resposta_coluna_alterada);
			if(Resposta_tabela.equalsIgnoreCase("Cliente")||Resposta_tabela.equalsIgnoreCase("Produtos")){
				
			String Resposta_coluna_alterada_valor1 = teclado.next();
			String Resposta_coluna_alterada_valor2 = teclado.next();
			String Resposta_coluna_alterada_valor3 = teclado.next();
			String Resposta_coluna_alterada_valor4 = teclado.next();
			
			Resposta_sql = "INSERT INTO "+Resposta_tabela+" ("+Resposta_coluna_alterada+") VALUES ('"+Resposta_coluna_alterada_valor1+"', '"+Resposta_coluna_alterada_valor2+"', '"+Resposta_coluna_alterada_valor3+"'"
					+ ", '"+Resposta_coluna_alterada_valor4+"')";
			
		//	INSERT INTO clientes (nome, email, empresa) VALUES ('Júnior', 'junior@dominio.com', 'RL System');
			
			}else if(Resposta_tabela.equalsIgnoreCase("Funcionarios")){
				
				String Resposta_coluna_alterada_valor1 = teclado.next();
				String Resposta_coluna_alterada_valor2 = teclado.next();
				String Resposta_coluna_alterada_valor3 = teclado.next();
				String Resposta_coluna_alterada_valor4 = teclado.next();
				String Resposta_coluna_alterada_valor5 = teclado.next();
				String Resposta_coluna_alterada_valor6 = teclado.next();
				
				Resposta_sql = "INSERT INTO "+Resposta_tabela+" ("+Resposta_coluna_alterada+") VALUES ('"+Resposta_coluna_alterada_valor1+"', '"+Resposta_coluna_alterada_valor2+"', '"+Resposta_coluna_alterada_valor3+"'"
						+ ", '"+Resposta_coluna_alterada_valor4+"', '"+Resposta_coluna_alterada_valor5+"', '"+Resposta_coluna_alterada_valor6+"')";	
				
			}else if(Resposta_tabela.equalsIgnoreCase("Fornecedores")){
				
				String Resposta_coluna_alterada_valor1 = teclado.next();
				String Resposta_coluna_alterada_valor2 = teclado.next();
				String Resposta_coluna_alterada_valor3 = teclado.next();	
				
				Resposta_sql = "INSERT INTO "+Resposta_tabela+" ("+Resposta_coluna_alterada+") VALUES ('"+Resposta_coluna_alterada_valor1+"', '"+Resposta_coluna_alterada_valor2+"', '"+Resposta_coluna_alterada_valor3+"')";
				
			}else{
				
				String Resposta_coluna_alterada_valor1 = teclado.next();
				String Resposta_coluna_alterada_valor2 = teclado.next();
				
				Resposta_sql = "INSERT INTO "+Resposta_tabela+" ("+Resposta_coluna_alterada+") VALUES ('"+Resposta_coluna_alterada_valor1+"', '"+Resposta_coluna_alterada_valor2+"')";
			}
				
			}else{
				
				
			System.out.println("qual o valor que "+Resposta_coluna_condicao+" Precisa ter para "+Resposta_alteracao+" o "+Resposta_coluna_alterada);
			Resposta_coluna_condicao_valor = teclado.next();
			
			
			}
			if(Resposta_Comando.equalsIgnoreCase("UPDATE")){
				
				System.out.println("qual será o novo valor de "+Resposta_coluna_alterada);
				Resposta_coluna_alterada_valor = teclado.next();
				
			Resposta_sql = Resposta_Comando+" "+Resposta_tabela+" SET "+Resposta_coluna_alterada+" = '"+Resposta_coluna_alterada_valor+"'where "+Resposta_coluna_condicao+" like '"+Resposta_coluna_condicao_valor+"'";
				
			}else if(Resposta_Comando.equalsIgnoreCase("DELETE")){
					
			Resposta_sql = Resposta_Comando+" "+Resposta_coluna_alterada+" from "+Resposta_tabela+" where "+Resposta_coluna_condicao+" like '"+Resposta_coluna_condicao_valor+"'";
			
			}else if(Resposta_Comando.equalsIgnoreCase("SELECT")){
				
			Resposta_sql = Resposta_Comando+" "+Resposta_coluna_alterada+" from "+Resposta_tabela+" where "+Resposta_coluna_condicao+" like '"+Resposta_coluna_condicao_valor+"'";
				
				
			}
			
			System.out.println("aperte qualquer tecla para executar sua instrução no BD");
			    
			String qualquer_tecla = teclado.next();
			    
			if(Resposta_alteracao.equalsIgnoreCase("Alterar")){
				
				BD.Comando_Alteracao(Resposta_sql);
				
			}else{
				
				System.out.println(BD.Comando_Consulta(Resposta_sql, Resposta_coluna_alterada));
				
			}
			

			System.out.println("Se Deseja continuar digite 0 para voltar ao começo do Menu, digite 1 para escrever outro valor digite 2 para acabar o programa");
			continuar = teclado.nextInt();
			
			
		}while(continuar == 1);

	
		
		
	         }
		}while(continuar == 0);
		
	}
}
