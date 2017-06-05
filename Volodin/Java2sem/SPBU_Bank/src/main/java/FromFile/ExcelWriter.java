package FromFile;

import org.apache.poi.ss.usermodel.Cell;
import org.apache.poi.ss.usermodel.Row;
import org.apache.poi.ss.usermodel.Sheet;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;

import java.io.FileOutputStream;
import java.io.OutputStream;
import java.lang.reflect.InvocationTargetException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ExcelWriter {
    private XSSFWorkbook xwb;
    void write(){
        xwb = new XSSFWorkbook ();
        writeClients();
        writeCredits();
        writeToFile();
    }

    private void writeCredits() {
        List<String> lsnames = new ArrayList<>(Arrays.asList(
                "ID Клиента", "Сумма", "Сумма к оплате", "Оплачено", "Процент", "Дата закрытия"
        ));
        List<String> fieldsNames = new ArrayList<>(Arrays.asList(
                "clientId", "sum", "sumToPay", "sumPaid", "percent", "dateToClose"
        ));

        List<Object> lob = new ArrayList<>();
        for (ClientInf cl : ClientStorage.getClientList())
            for (CreditInf cr : cl.getCredits())
                lob.add(cr);

        writeInf("Credits", lsnames, fieldsNames, lob);
    }

    private void writeClients(){
        List<String> lsnames = new ArrayList<>(Arrays.asList(
                "ID", "Фамилия", "Имя", "Отчество", "Паспорт", "Телефон", "Дата рождения", "Старый паспорт"
        ));
        List<String> fieldsNames = new ArrayList<>(Arrays.asList(
                "id", "family", "name", "father", "passport", "phone", "birthDate", "oldpas"
        ));

        List<Object> lob = new ArrayList<>();
        for (Object c : ClientStorage.getClientList())
            lob.add(c);

        writeInf("Clients", lsnames, fieldsNames, lob);
    }

    private void writeInf(String sheetName, List<String> lsnames, List<String> fieldsNames, List<Object> objList){
        Sheet sheet = xwb.createSheet(sheetName);
        writeFirstRow(sheet, lsnames);
        List<String> methodNames = getMethodNames(fieldsNames);
        fillInfRows(sheet, methodNames, objList);
    }

    private void fillInfRows(Sheet sheet, List<String> methodNames, List<Object> objList) {
        int rownum = 1;
        for (Object obj : objList) {
            Row r = sheet.createRow(rownum++);
            int rowcell = 0;
            for (String methodName : methodNames) {
                Cell c = r.createCell(rowcell++);
                try {
                    c.setCellValue(String.valueOf(obj.getClass().getMethod(methodName).invoke(obj)));
                } catch (IllegalAccessException | InvocationTargetException | NoSuchMethodException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    private void writeFirstRow(Sheet sheet, List<String> lsnames) {
        Row r1 = sheet.createRow(0);
        int rowcell = 0;
        for (String name : lsnames){
            Cell c = r1.createCell(rowcell++);
            c.setCellValue(name);
        }
    }

    private List<String> getMethodNames(List<String> fieldsNames) {
        List<String> methodNames = new ArrayList<>();
        for (String name : fieldsNames){
            StringBuilder namb = new StringBuilder(name);
            namb.setCharAt(0, Character.toUpperCase(name.charAt(0)));
            StringBuilder t = new StringBuilder("get");
            t.append(namb);
            methodNames.add(t.toString());
        }
        return methodNames;
    }

    private void writeToFile(){
        try {
            OutputStream os = new FileOutputStream("Output.xlsx");
            xwb.write(os);
            os.close();
        } catch (java.io.IOException e) {
            e.printStackTrace();
        }
    }
}
