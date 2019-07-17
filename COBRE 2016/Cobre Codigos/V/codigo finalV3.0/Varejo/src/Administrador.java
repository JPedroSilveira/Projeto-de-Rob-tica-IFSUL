
public class Administrador{
	
	String Permissoes = "Alteração e consulta de dados.";
	String Permissoes_Tabela = "Senha, Fornecedores, Cliente, Produtos, Funcionarios";

	public String getPermissoes() {
		return Permissoes;
	}

	public void setPermissoes(String permissoes) {
		Permissoes = permissoes;
	}

	public String getPermissoes_Tabela() {
		return Permissoes_Tabela;
	}

	public void setPermissoes_Tabela(String permissoes_Tabela) {
		Permissoes_Tabela = permissoes_Tabela;
	}
	
	

}
