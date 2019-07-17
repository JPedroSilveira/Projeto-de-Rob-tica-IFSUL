import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class ConnectionFactory {
	public Connection getConnection() {
//DELETE * FROM SLA WHERE SLA2=SLA3 AND OI=TCHAU
		try {

			return DriverManager.getConnection("jdbc:mysql://localhost:3306/Varejo", "root", "");

		} catch (SQLException e) {

			throw new RuntimeException(e);

		}

	}
}