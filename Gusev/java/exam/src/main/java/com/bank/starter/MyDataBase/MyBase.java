package com.bank.starter.MyDataBase;

import com.bank.starter.ExamTaskControllers.RandomUserService;
import com.bank.starter.models.User;
import com.bank.starter.models.ServerAnswer;
import org.apache.poi.hssf.usermodel.HSSFCellStyle;
import org.apache.poi.hssf.usermodel.HSSFFont;
import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import org.apache.poi.hssf.util.HSSFColor;
import org.apache.poi.ss.usermodel.Row;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.web.client.RestTemplate;

import java.io.FileOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collection;

/**
 * Created by gusef on 26.05.2017.
 */
@Service
public class MyBase implements MyDataBase {

    @Autowired
    private RandomUserService randomUserService;

    private ArrayList<User> Users = new ArrayList<>();

    @Override
    public ArrayList<User> getArrayListOfUsers(){
        return Users;
    }

    @Override
    public void addUser(User newUser) {
        Users.add(newUser);
    }

    @Override
    public void addAllUsers(Collection<User> newUsers) {
        Users.addAll(newUsers);
    }

    @Override
    public void getRandomUsers(int number){
        String API_PATH = "https://randomuser.me/api?results=";
        RestTemplate template = new RestTemplate();
        ServerAnswer serverAnswer = template.getForObject(API_PATH + Integer.toString(number),ServerAnswer.class);
        addAllUsers(serverAnswer.getResults());
    }

    @Override
    public void outDataToExcel(FileOutputStream outFile) throws IOException {

        // создание самого excel файла в памяти
        HSSFWorkbook workbook = new HSSFWorkbook();
        HSSFSheet sheetUsers = workbook.createSheet("Люди");

        HSSFFont font = workbook.createFont();
        font.setBold(true);
        HSSFCellStyle style = workbook.createCellStyle();
        style.setFont(font);

        HSSFCellStyle hLinkStyle = workbook.createCellStyle();
        HSSFFont hLinkFont = workbook.createFont();
        hLinkFont.setUnderline(HSSFFont.U_SINGLE);
        hLinkFont.setColor(HSSFColor.BLUE.index);
        hLinkStyle.setFont(hLinkFont);

        // счетчик для строк
        int rowNumUsers = 0;

        // создаем подписи к столбцам (это будет первая строчка в листе Excel файла)
        Row rowClients = sheetUsers.createRow(rowNumUsers);
        rowClients.createCell(0).setCellValue("клиент");
        rowClients.createCell(1).setCellValue("Имя");
        rowClients.createCell(2).setCellValue("Фамилия");
        rowClients.createCell(3).setCellValue("username");
        rowClients.createCell(4).setCellValue("адрес");
        rowClients.createCell(5).setCellValue("email");
        rowClients.createCell(6).setCellValue("фото");

        Row rowChange = sheetUsers.getRow(0);
        for (int i = 0; i < rowChange.getPhysicalNumberOfCells(); i++)
            rowChange.getCell(i).setCellStyle(style);
        sheetUsers.autoSizeColumn(rowNumUsers);

        // заполняем лист данными
        for (User person : Users) {
            rowNumUsers++;
            Row rowFile = sheetUsers.createRow(rowNumUsers);
            rowFile.createCell(0).setCellValue(rowNumUsers);
            rowFile.createCell(1).setCellValue(person.getName().getFirst());
            rowFile.createCell(2).setCellValue(person.getName().getLast());
            rowFile.createCell(3).setCellValue(person.getLogin().getUsername());
            rowFile.createCell(4).setCellValue(person.getLocation().getState() + ", " +
                    person.getLocation().getCity() + ", " +
                    person.getLocation().getStreet());
            rowFile.createCell(5).setCellValue(person.getEmail());
            //XSSFHyperlink link = (XSSFHyperlink)createHelper
            //        .createHyperlink(Hyperlink.LINK_URL);
            rowFile.createCell(6).setCellValue(person.getPicture().getLarge());
            rowFile.getCell(6).setCellStyle(hLinkStyle);
            sheetUsers.autoSizeColumn(rowNumUsers);
        }

        // записываем созданный в памяти Excel документ в файл
        workbook.write(outFile);
        System.out.println("Excel file was successfully created!");
    }
}
