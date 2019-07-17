import java.sql.ResultSet;
import java.sql.SQLException;
import java.text.ParseException;
import java.util.Date;
import java.util.Scanner;

import com.mysql.jdbc.Connection;
import com.mysql.jdbc.PreparedStatement;

public class ComandoBD {

	public void Comando_Alteracao(String Resposta){
		
		try {
			   Connection con = (Connection) new ConnectionFactory().getConnection();
			   
			   String sql = Resposta;
			   
			   PreparedStatement pegar = (PreparedStatement) con.prepareStatement(sql);
			   int rs = pegar.executeUpdate(sql);
			   System.out.println(rs+" foram alterados com sucesso");
			   con.close();
			   
			  } catch (SQLException e) {
			   Resposta = "Ocorreu um erro. Contacte o administrador do sistema.";
			   System.out.println(Resposta);
			  
			  }		
	}
	
	public String Comando_Consulta(String Resposta, String GET){
		
		
		
		try {
			Connection con = (Connection) new ConnectionFactory().getConnection();
			String sql = Resposta;
			PreparedStatement pegar = (PreparedStatement) con.prepareStatement(sql);
			ResultSet rs = pegar.executeQuery(sql);
			rs.next();
			Resposta = rs.getString(GET);
			rs.close();
			con.close();
			} catch (SQLException e) {
			System.out.println("Ocorreu um erro. Contacte o administrador do sistema.");
			Resposta = null;
			}
		
		return Resposta;
		
	}

}
