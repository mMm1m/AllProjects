// подключение классов для работы с сетью
import java.net.*;
//классы для работы с сетью
import java.io.*;
public class Server {
    public static void main(String[] args) throws IOException {
        // создать серверное подключение и создать ожидание клиента
        try(ServerSocket serverSocket = new ServerSocket(8080))
        {
        // Реализация многоразового сервера
        while(true) {

            // начинаем прослушивать порт, указанный в создании
            // экземпляра сокет, завершается при подключении клиента
            Socket clientSocket = serverSocket.accept();
            BufferedReader reader = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            // создаём обёртку на OutputStream, создание объекта,
            // записывающего информацию в поток вывода

            OutputStreamWriter writer = new OutputStreamWriter(clientSocket.getOutputStream());

            String request = reader.readLine();
            String response = "Your request's length is: " + request.length() + "\n";
            writer.write(request + "\n");
            writer.write(response + "\n");
            // сокет находится на стороне клиента, а серверный сокет
            // на стороне сервера. ПЛЮС серверный сокет постоянно прослушивает
            // указанный порт, чтобы поймать данные от клиента

            // отправка через сокет; выполняется через поток

            //clientSocket.getOutputStream().write("<h2>Hello</h2>".getBytes());
            writer.close();
            reader.close();
          //  if(counter == 5) break;
        }
        //serverSocket.close();
        }
    }

}
