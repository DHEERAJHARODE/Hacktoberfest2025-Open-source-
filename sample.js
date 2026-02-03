$(document).ready(function(){
    $("#sign_up").validate({
        rules:{
            fname:{
                required:true
            },
            sname:{
                required:true
            },
            emailAdress:{
                required:true,
                email:true
            },
            pass:{
                required:true,
                minlength:8
            },
            day:{
                required:true
            },
            month:{
                required:true
            },
            year:{
                required:true
            },
            gender:{
                required:true,
            }
        },
        messages:{
            fname:"Enter your name",
            sname:"Enter your name",
            emailAdress:"enter a valid Email",
            day:"Day??",
            month:"Month??",
            year:"Year??",
            pass:"Enter Password",
            gender:"select your Gender"
        },
    })
})