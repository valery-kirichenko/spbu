package com.MyProj.MyProj;
import org.springframework.stereotype.Component;

import java.util.List;
import java.util.Map;
/**
 * Created by Lenovo on 20.06.2017.
 */
public class ServAns {
    List<Map<String, Object> > results;
    public List<Map<String, Object>> getResults() {
        return results;
    }
}
