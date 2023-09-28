package com.library.librarywebservice;

import com.fasterxml.jackson.databind.util.JSONPObject;
import netscape.javascript.JSObject;
import org.json.*;
import org.springframework.http.MediaType;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/tmp")
public class RequestController {
    JSONObject jsonObject  = new JSONObject();
    JSONObject t = jsonObject.put("sxxs", "ecerc");

    @GetMapping("/next")
    public void showURL()
    {
        System.out.println(t);
    }
}
