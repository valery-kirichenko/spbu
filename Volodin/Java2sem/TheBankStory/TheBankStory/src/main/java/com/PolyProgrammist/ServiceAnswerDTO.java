package com.PolyProgrammist;

import org.springframework.stereotype.Service;

import java.util.List;
import java.util.Map;
@Service
public class ServiceAnswerDTO {
    List<Map <String, Object> > results;

    public List<Map<String, Object>> getResults() {
        return results;
    }

    public void setResults(List<Map<String, Object>> results) {
        this.results = results;
    }
}