const countries = {
    "am-ET": "Amharic",
    "ar-SA": "Arabic",
    "be-BY": "Bielarus",
    "bem-ZM": "Bemba",
    "bi-VU": "Bislama",
    "bjs-BB": "Bajan",
    "bn-IN": "Bengali",
    "bo-CN": "Tibetan",
    "br-FR": "Breton",
    "bs-BA": "Bosnian",
    "ca-ES": "Catalan",
    "cop-EG": "Coptic",
    "cs-CZ": "Czech",
    "cy-GB": "Welsh",
    "da-DK": "Danish",
    "dz-BT": "Dzongkha",
    "de-DE": "German",
    "dv-MV": "Maldivian",
    "el-GR": "Greek",
    "en-GB": "English",
    "es-ES": "Spanish",
    "et-EE": "Estonian",
    "eu-ES": "Basque",
    "fa-IR": "Persian",
    "fi-FI": "Finnish",
    "fn-FNG": "Fanagalo",
    "fo-FO": "Faroese",
    "fr-FR": "French",
    "gl-ES": "Galician",
    "gu-IN": "Gujarati",
    "ha-NE": "Hausa",
    "he-IL": "Hebrew",
    "hi-IN": "Hindi",
    "hr-HR": "Croatian",
    "hu-HU": "Hungarian",
    "id-ID": "Indonesian",
    "is-IS": "Icelandic",
    "it-IT": "Italian",
    "ja-JP": "Japanese",
    "kk-KZ": "Kazakh",
    "km-KM": "Khmer",
    "kn-IN": "Kannada",
    "ko-KR": "Korean",
    "ku-TR": "Kurdish",
    "ky-KG": "Kyrgyz",
    "la-VA": "Latin",
    "lo-LA": "Lao",
    "lv-LV": "Latvian",
    "men-SL": "Mende",
    "mg-MG": "Malagasy",
    "mi-NZ": "Maori",
    "ms-MY": "Malay",
    "mt-MT": "Maltese",
    "my-MM": "Burmese",
    "ne-NP": "Nepali",
    "niu-NU": "Niuean",
    "nl-NL": "Dutch",
    "no-NO": "Norwegian",
    "ny-MW": "Nyanja",
    "ur-PK": "Pakistani",
    "pau-PW": "Palauan",
    "pa-IN": "Panjabi",
    "ps-PK": "Pashto",
    "pis-SB": "Pijin",
    "pl-PL": "Polish",
    "pt-PT": "Portuguese",
    "rn-BI": "Kirundi",
    "ro-RO": "Romanian",
    "ru-RU": "Russian",
    "sg-CF": "Sango",
    "si-LK": "Sinhala",
    "sk-SK": "Slovak",
    "sm-WS": "Samoan",
    "sn-ZW": "Shona",
    "so-SO": "Somali",
    "sq-AL": "Albanian",
    "sr-RS": "Serbian",
    "sv-SE": "Swedish",
    "sw-SZ": "Swahili",
    "ta-LK": "Tamil",
    "te-IN": "Telugu",
    "tet-TL": "Tetum",
    "tg-TJ": "Tajik",
    "th-TH": "Thai",
    "ti-TI": "Tigrinya",
    "tk-TM": "Turkmen",
    "tl-PH": "Tagalog",
    "tn-BW": "Tswana",
    "to-TO": "Tongan",
    "tr-TR": "Turkish",
    "uk-UA": "Ukrainian",
    "uz-UZ": "Uzbek",
    "vi-VN": "Vietnamese",
    "wo-SN": "Wolof",
    "xh-ZA": "Xhosa",
    "yi-YD": "Yiddish",
    "zu-ZA": "Zulu"
}

const selectTag=document.querySelectorAll("select");
const body=document.getElementById("body")
const translateBtn=document.getElementById("btn");
const inputText=document.getElementById("translate");
const outputText=document.getElementById("translated");
const exchange=document.getElementById("exchange");
const icons=document.querySelectorAll(".row i")
selectTag.forEach((tag,id) => {
    for(const country_code in countries) {
        let selected;
        if(id==0 && country_code=="en-GB"){
            selected="selected";
        }
        else if(id==1 && country_code=="hi-IN"){
            selected="selected";
        }
        console.log(countries[country_code]);
        let option=`<option value="${country_code}"${selected}>${countries[country_code]}</option>`;
        tag.insertAdjacentHTML("beforeend",option);
    }
});
translateBtn.addEventListener("click",()=>{
    let text=body.value;
    let translateFrom=selectTag[0].value;
    let translateTo=selectTag[1].value;
    console.log(text,translateFrom,translateTo);
    let apiUrl=`https://api.mymemory.translated.net/get?q=${text}&langpair=${translateFrom}|${translateTo}`;
    fetch(apiUrl).then(res => res.json()).then(data=>{
        console.log(data);
//   outputText.value=data.responseData.translatedText;
body.value=data.responseData.translatedText;

    })


})

exchange.addEventListener("click",()=>{
    let tempText=body.value;
    body.value=body.value;
    body.value=tempText;
    let tempLang=selectTag[0].value;
    selectTag[0].value=selectTag[1].value;
    selectTag[1].value=tempLang;
})
icons.forEach(icon=>{ 
icon.addEventListener("click",({target})=>{
 if(target.classList.contains("fa-copy")){
     if(target.id=="from"){
    navigator.clipboard.writeText(body.value);
     }
     else{
       navigator.clipboard.writeText(body.value);
     }
    }
     else{
        let utterance;
        if(target.id=="from"){
           utterance=new SpeechSynthesisUtterance(inputText.value);
           utterance.lang=selectTag[0].value;
             }
             else{
               utterance=new SpeechSynthesisUtterance(outputText.value);
               utterance.lang=selectTag[1].value;
             }
             speechSynthesis.speak(utterance);
     }

});
})