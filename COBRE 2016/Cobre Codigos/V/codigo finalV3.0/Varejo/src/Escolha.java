import java.util.Scanner;
public class Escolha {

	Scanner teclado = new Scanner (System.in);
	
	
	public String Coluna(String Resposta_tabela, int Modo){
		String Resposta_coluna = null;
		int continuar = 0;
		
		do{
		
		continuar = 0;
		
		if(Modo == 0){
			
			System.out.println("Escolha a coluna que deseja consultar ou alterar");
			
		}else if(Modo == 1){
		
			System.out.println("Escolha a coluna que deseja usar como condição para sua alteração ou consulta");
		
		}else{
			
			System.out.println("Escolha a coluna que você que deseja inserir seus dados");
			
		}
		if(Resposta_tabela.equalsIgnoreCase("Cliente")){
			
			System.out.println("RG, CPF, Nome, Contato");
			Resposta_coluna = teclado.next();
			
			if(Resposta_coluna.equalsIgnoreCase("RG") || Resposta_coluna.equalsIgnoreCase("CPF")
			|| Resposta_coluna.equalsIgnoreCase("Nome")|| Resposta_coluna.equalsIgnoreCase("Contato")){					
			}else{
				
				continuar = 1;
				System.out.println(Resposta_tabela + " não consta no sistema.");				
			}
			
		}else if(Resposta_tabela.equalsIgnoreCase("Produtos")){
			
			System.out.println("Preços, Nome, Marca, Fornecedor");
			Resposta_coluna = teclado.next();
			
			if(Resposta_coluna.equalsIgnoreCase("Preços") || Resposta_coluna.equalsIgnoreCase("Nome")
			|| Resposta_coluna.equalsIgnoreCase("Marca")|| Resposta_coluna.equalsIgnoreCase("Fornecedor")){					
			}else{
				
				continuar = 1;
				System.out.println(Resposta_tabela + " não consta no sistema.");				
			}
			
			
		}else if(Resposta_tabela.equalsIgnoreCase("Funcionarios")){
			
			
			System.out.println("Cargo, Nome, RG, CPF, Salario, Carga_horaria");
			Resposta_coluna = teclado.next();
			
			if(Resposta_coluna.equalsIgnoreCase("Cargo") || Resposta_coluna.equalsIgnoreCase("Nome")
			|| Resposta_coluna.equalsIgnoreCase("RG")|| Resposta_coluna.equalsIgnoreCase("CPF")
			|| Resposta_coluna.equalsIgnoreCase("Salario")|| Resposta_coluna.equalsIgnoreCase("Carga_horaria")){					
			}else{
				
				continuar = 1;
				System.out.println(Resposta_tabela + " não consta no sistema.");				
			}
			
			
			
			
		}else if(Resposta_tabela.equalsIgnoreCase("Fornecedores")){
			
			
			System.out.println("Nome, Produtos, Contato");
			Resposta_coluna = teclado.next();
			
			if(Resposta_coluna.equalsIgnoreCase("Nome") || Resposta_coluna.equalsIgnoreCase("Produtos")
			|| Resposta_coluna.equalsIgnoreCase("Contato")){					
			
			}else{
				
				continuar = 1;
				System.out.println(Resposta_tabela + " não consta no sistema.");
				
			}
			
			
		}else if(Resposta_tabela.equalsIgnoreCase("Senha")){
			
			
			System.out.println("Cargo, Senha");
			Resposta_coluna = teclado.next();
			
			if(Resposta_coluna.equalsIgnoreCase("Cargo") || Resposta_coluna.equalsIgnoreCase("Senha")){					
			}else{
				
				continuar = 1;
				System.out.println(Resposta_tabela + " não consta no sistema.");				
			}
			
			
			
		}
		
		
	}while(continuar == 1);
		return Resposta_coluna;
	
	
	
	
}
}