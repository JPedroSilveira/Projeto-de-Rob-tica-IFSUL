
public class Alterador {
	
	Secretaria S = new Secretaria();
	Gerente G = new Gerente();
	Administrador A = new Administrador();
	
	public String permissoes(String Resposta){
		
		if(Resposta.equalsIgnoreCase("Secretária")){
			
			Resposta = this.S.getPermissoes();
			
			
			
		}else if(Resposta.equalsIgnoreCase("Gerente")){
			
			Resposta = this.G.getPermissoes();
			
			
		}else{
			
			Resposta = this.A.getPermissoes();
			
			
		}
		
		return Resposta;
		
	}
	
public String permissoes_Tabela(String Resposta){	

		
		if(Resposta.equalsIgnoreCase("Secretária")){
			
			Resposta = this.S.getPermissoes_Tabela();
			
			
			
		}else if(Resposta.equalsIgnoreCase("Gerente")){
			
			Resposta = this.G.getPermissoes_Tabela();
			
			
		}else{
			
			Resposta = this.A.getPermissoes_Tabela();
			
			
		}
		
		return Resposta;
		
	}

public String permissoes_Tabela_logico(String Resposta, String Tabela){
	
	
	if(Resposta.equalsIgnoreCase("Secretária")){
		
		if(Tabela.equalsIgnoreCase("Cliente")){
			
			Resposta = "Cliente";
			
		}else if(Tabela.equalsIgnoreCase("Produtos")){
			
			Resposta = "Produtos";
			
		}else{
			
		Resposta = " ";
			
		}
		
		
		
	}else if(Resposta.equalsIgnoreCase("Gerente")){
		
		
if(Tabela.equalsIgnoreCase("Cliente")){
			
			Resposta = "Cliente";
			
		}else if(Tabela.equalsIgnoreCase("Produtos")){
			
			Resposta = "Produtos";
			
		}else if(Tabela.equalsIgnoreCase("Funcionarios")){
			
			Resposta = "Funcionarios";
			
		}else{
			
			Resposta = " ";
			
		}
		
		
	}else{
		
		
        if(Tabela.equalsIgnoreCase("Cliente")){
			
			Resposta = "Cliente";
			
		}else if(Tabela.equalsIgnoreCase("Produtos")){
			
			Resposta = "Produtos";
			
		}else if(Tabela.equalsIgnoreCase("Funcionarios")){
			
			Resposta = "Funcionarios";
			
		}else if(Tabela.equalsIgnoreCase("Senha")){
			
			Resposta = "Senha";
			
		}else if(Tabela.equalsIgnoreCase("Fornecedores")){
			
			Resposta = "Fornecedores";
			
		}
		
		
	}
		
	return Resposta;
	
}
	
public String permissoes_alteracao(String Resposta, String Tabela){
	
if(Resposta.equalsIgnoreCase("Secretária")){
		
		if(Tabela.equals("Cliente")){
			
			Resposta = "alterar e consultar";
			
		}else if(Tabela.equalsIgnoreCase("Produtos")){
			
			Resposta = "consultar";
			
		}
		
		
		
	}else if(Resposta.equalsIgnoreCase("Gerente")){
		
		
if(Tabela.equalsIgnoreCase("Cliente")){
			
			Resposta = "alterar e consultar";
			
		}else if(Tabela.equalsIgnoreCase("Produtos")){
			
			Resposta = "alterar e consultar";
			
		}else if(Tabela.equalsIgnoreCase("Funcionarios")){
			
			Resposta = "consultar";
			
		}
		
		
	}else{
		
		
       Resposta = "alterar e consultar";
		
		
	}
	
	return Resposta;
}
	
	
	

}
