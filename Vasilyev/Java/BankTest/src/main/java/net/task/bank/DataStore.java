package net.task.bank;

import com.opencsv.CSVWriter;
import com.sun.istack.internal.Nullable;
import org.apache.poi.hssf.usermodel.HSSFCellStyle;
import org.apache.poi.hssf.usermodel.HSSFFont;
import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import org.apache.poi.ss.usermodel.CellStyle;
import org.apache.poi.ss.usermodel.DataFormat;
import org.apache.poi.ss.usermodel.Row;

import java.io.*;
import java.util.ArrayList;


public class DataStore {
    //Создать класс, который умеет собирать данные из файлов в общую базу данных,
    //притом дублирующиеся пользователи должны быть объединены, а буква ё должна быть заменена на е. (!)
    //Не потеряйте кредиты из аккаунтов дублей. Merge клиентов лучше оформить отдельным методом.
    public ArrayList<Client> clients = new ArrayList<>();
    public ArrayList<Credit> credits = new ArrayList<>();
    public ArrayList<Integer> deletedClients = new ArrayList<>();
    public static int countNull = 0;

    DataStore() {
    }

    //Пользователи содержат битые записи. Может быть несколько записей с одинаковым номером паспорта и именем фамилией.
    //Результат повторного заведения одних и тех же пользователей.
    //Может быть несколько пользователей у которых новый паспорт и старый паспорт совпадает
    //(пользователь сменил паспорт, завели новый аккаунт, притом может даже поменяться фамилия).
    public void mergeDuplicate() {
        int countDup = 0, countError = 0;

        for (Client client1 : clients) {
            for (Client client2 : clients) {
                if (!client1.equals(client2) && !client1.isDeleted && !client2.isDeleted) {
                    if (client1.getPassport() == client2.getPassport()) {
                        for (Credit credit2 : credits) {
                            if (credit2.getId() == client2.getId()) {
                                credit2.setId(client1.getId());
                            }
                        }
                        countDup++;
                        //deletedClients.add(client2.getId());
                        client2.isDeleted = true;
                        break;
                    } else if (client1.getOldPassport() == client2.getPassport()) {
                        for (Credit credit2 : credits) {
                            if (credit2.getId() == client2.getId()) {
                                credit2.setId(client1.getId());
                            }
                        }
                        countError++;
                        //deletedClients.add(client2.getId());
                        client2.isDeleted = true;
                        break;
                    }
                }
            }
        }
        System.out.println("Number of duplicates: " + countDup + " real duplicates, " +
                countError + " confusion with passports.");
        ArrayList<Client> newClients = new ArrayList<>();
        for (Client client : clients)
            if (!client.isDeleted)
                newClients.add(client);
        clients = newClients;

        for (Client client : clients)
            for (Credit credit : credits)
                if (credit.getId() == client.getId())
                    client.addCredit(credit);
    }

    public void outDataToTxt(FileOutputStream outClients, FileOutputStream outCredits) throws IOException {
        for (Client client : clients) {
            if (client.getOldPassport() == 0) {
                outClients.write((client.getId() + " " + client.getName() + " " + client.getMiddlename() + " " +
                        client.getLastname() + " " + client.getPhone() + " " + client.getPassport() + " "
                        + client.getBirthday() + "\n").getBytes());
            } else {
                outClients.write((client.getId() + " " + client.getName() + " " + client.getMiddlename() + " " +
                        client.getLastname() + " " + client.getPhone() + " " + client.getPassport() + " "
                        + client.getBirthday() + " " + client.getOldPassport() + "\n").getBytes());
            }
        }

        for (Credit credit : credits) {
            outCredits.write((credit.getId() + " " + credit.getAmount() + " " + credit.getPercent() + " " +
                    credit.getPaidSum() + " " + credit.getNeedPaid() + " " + credit.getClosingDate() +
                    "\n").getBytes());
        }
    }

    public void outDataToCsv(CSVWriter writerClients, CSVWriter writerCredits) throws IOException {
        for (Client client : clients) {
            if (client.getOldPassport() == 0) {
                String[] entries = (client.getId() + " " + client.getName() + " " + client.getMiddlename() + " " +
                        client.getLastname() + " " + client.getPhone() + " " + client.getPassport() + " "
                        + client.getBirthday()).split(" ");
                writerClients.writeNext(entries);
            } else {
                String[] entries = (client.getId() + " " + client.getName() + " " + client.getMiddlename() + " " +
                        client.getLastname() + " " + client.getPhone() + " " + client.getPassport() + " "
                        + client.getBirthday() + " " + client.getOldPassport()).split(" ");
                writerClients.writeNext(entries);
            }
        }

        for (Credit credit : credits) {
            String[] entries = (credit.getId() + " " + credit.getAmount() + " " + credit.getPercent() + " " +
                    credit.getPaidSum() + " " + credit.getNeedPaid() + " "
                    + credit.getClosingDate()).split(" ");
            writerCredits.writeNext(entries);
        }
    }

    public void outDataToExcel(FileOutputStream outFile) throws IOException {

        // создание самого excel файла в памяти
        HSSFWorkbook workbook = new HSSFWorkbook();
        HSSFSheet sheetClients = workbook.createSheet("Клиенты");
        HSSFSheet sheetCredits = workbook.createSheet("Кредиты");

        HSSFFont font = workbook.createFont();
        font.setBold(true);
        HSSFCellStyle style = workbook.createCellStyle();
        style.setFont(font);

        DataFormat format = workbook.createDataFormat();
        CellStyle dateStyle = workbook.createCellStyle();
        dateStyle.setDataFormat(format.getFormat("dd.mm.yyyy"));

        // счетчик для строк
        int rowNumClients = 0, rowNumCredits = 0;

        // создаем подписи к столбцам (это будет первая строчка в листе Excel файла)
        Row rowClients = sheetClients.createRow(rowNumClients);
        rowClients.createCell(0).setCellValue("ID клиента");
        rowClients.createCell(1).setCellValue("Имя");
        rowClients.createCell(2).setCellValue("Отчество");
        rowClients.createCell(3).setCellValue("Фамилия");
        rowClients.createCell(4).setCellValue("Телефон");
        rowClients.createCell(5).setCellValue("Паспорт");
        rowClients.createCell(6).setCellValue("День рождения");
        rowClients.createCell(7).setCellValue("Старый паспорт");

        Row rowCredits = sheetCredits.createRow(rowNumCredits);
        rowCredits.createCell(0).setCellValue("ID клиента");
        rowCredits.createCell(1).setCellValue("Сумма");
        rowCredits.createCell(2).setCellValue("Процент");
        rowCredits.createCell(3).setCellValue("Выплаченная сумма");
        rowCredits.createCell(4).setCellValue("Сумма к выплате");
        rowCredits.createCell(5).setCellValue("Дата закрытия");

        Row rowChange = sheetClients.getRow(0);
        for (int i = 0; i < rowChange.getPhysicalNumberOfCells(); i++)
            rowChange.getCell(i).setCellStyle(style);
        rowChange = sheetCredits.getRow(0);
        for (int i = 0; i < rowChange.getPhysicalNumberOfCells(); i++)
            rowChange.getCell(i).setCellStyle(style);
        sheetClients.autoSizeColumn(rowNumClients);
        sheetCredits.autoSizeColumn(rowNumCredits);

        // заполняем лист данными
        for (Client client : clients) {
            rowNumClients++;
            Row rowFile = sheetClients.createRow(rowNumClients);
            rowFile.createCell(0).setCellValue(client.getId());
            rowFile.createCell(1).setCellValue(client.getName());
            rowFile.createCell(2).setCellValue(client.getMiddlename());
            rowFile.createCell(3).setCellValue(client.getLastname());
            rowFile.createCell(4).setCellValue(client.getPhone());
            rowFile.createCell(5).setCellValue(client.getPassport());
            rowFile.createCell(6).setCellValue(client.getBirthday());
            rowFile.getCell(6).setCellStyle(dateStyle);
            if (client.getOldPassport() != 0) {
                rowFile.createCell(7).setCellValue(client.getOldPassport());
            }
            sheetClients.autoSizeColumn(rowNumClients);
        }

        for (Credit credit : credits) {
            rowNumCredits++;
            Row rowFile = sheetCredits.createRow(rowNumCredits);
            rowFile.createCell(0).setCellValue(credit.getId());
            rowFile.createCell(1).setCellValue(credit.getAmount());
            rowFile.createCell(2).setCellValue(credit.getPercent());
            rowFile.createCell(3).setCellValue(credit.getPaidSum());
            rowFile.createCell(4).setCellValue(credit.getNeedPaid());
            rowFile.createCell(5).setCellValue(credit.getClosingDate());
            rowFile.getCell(5).setCellStyle(dateStyle);
            sheetCredits.autoSizeColumn(rowNumCredits);
        }

        // записываем созданный в памяти Excel документ в файл
        workbook.write(outFile);
        System.out.println("Excel file was successfully created!");
    }

    public void changeName() {
        for (Client client : clients) {
            if (client.getName().contains("ё"))
                client.setName(client.getName().replace('ё', 'е'));
            if (client.getMiddlename().contains("ё"))
                client.setMiddlename(client.getMiddlename().replace('ё', 'е'));
            if (client.getLastname().contains("ё"))
                client.setLastname(client.getLastname().replace('ё', 'е'));
        }
    }

    @Nullable
    public String getNameFromId(int id) {
        for (Client client : clients)
            if (id == client.getId())
                return (client.getName() + " " + client.getMiddlename() + " " + client.getLastname());
        countNull++;
        return null;
    }
}
