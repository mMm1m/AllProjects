import java.io.*;
import java.net.Socket;

public class Client {
    public static void main(String[] args) throws IOException {
        Socket clientSocket = new Socket("127.0.0.1", 8080);
        // без запуска сервера клиент упадёт с ошибкой

        // в отличие от сервера, где был серверный клиент-сокет,
        // здесь он принадлежит клиенту
        // получаем от сокета поток вывода
        OutputStreamWriter outputStreamWriter = new OutputStreamWriter(clientSocket.getOutputStream());
        outputStreamWriter.write("IT_______WORKS!!!!\n");
        // гарантирует что сообщение будет отправлено, из-за кэширования
        outputStreamWriter.flush();

        BufferedReader reader = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
        String msg = reader.readLine();
        System.out.println(msg);
        // завершение работы сокета при подключении клиента к серверу
        outputStreamWriter.close();
        reader.close();
        clientSocket.close();
    }
}
