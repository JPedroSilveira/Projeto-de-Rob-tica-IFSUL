import java.util.Scanner;

public class Login {
	
	Scanner teclado = new Scanner (System.in);
	ComandoBD BD = new ComandoBD();
	
	public String Sequencia_Login(){
		
		
		int continuar;
		String Estado = null;
		String Resposta = null;
		String Resposta_senha = null;
		String Resposta_sql = null;
		
		do{
	
		continuar = 0;
		
		System.out.println("Selecione seu cargo, a partir do ID:\n");
		System.out.println("Secretario(a)    ID: 0\nGerente          ID: 1\nAdministrador(a) ID: 2");
		int Resposta_cargo = teclado.nextInt();
		
		switch (Resposta_cargo){
		
		case 0:
			
			Resposta = "Secretario(a)";
			
			break;
			
		case 1:
			
			Resposta = "Gerente";
			
			break;
			
		case 2:
			
			Resposta = "Administrador(a)";
			
			break;
			
		default: 
				
			System.out.println("Você digitou algo errado. Tente Novamente.");
			continuar = 1;
			
			break;
			
		}
		
	}while(continuar == 1);
	
	do{	
	continuar = 0;
	
	System.out.println("\n" + Resposta + ":\n");
	
	System.out.println("Digite a senha:");
	
	System.out.println("\n(Senhas)\n|Secretaria = 123   |\n|Gerencia = 321     |\n|Administração = 231|");
	Resposta_senha = teclado.next();
	
    Resposta_sql = "SELECT Senha FROM Senha WHERE Cargo = '"+Resposta+"';";
	if(Resposta_senha.equals(BD.Comando_Consulta(Resposta_sql, "Senha"))){
		
	}else{
		continuar = 1;
		System.out.println("Senha incorreta!");
	}
	
	
	
	}while(continuar == 1);
	
	return Resposta;
		
	}
}
