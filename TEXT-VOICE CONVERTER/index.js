let speech=new SpeechSynthesisUtterance();
let command=document.getElementById("command");
let btn=document.getElementById("lisbtn")
let voicesSelect=document.getElementById("voices")
let voices=[]
window.speechSynthesis.onvoiceschanged=()=>{
voices=window.speechSynthesis.getVoices();
speech.voice=voices[0];
voices.forEach((voice,i)=>
    (voicesSelect.options[i]=new Option(voice.name,i)));
};
voicesSelect.addEventListener("change",()=>{
    speech.voice=voices[voicesSelect.value];
})
 function convertspeech(){
    speech.text = command.value;
    window.speechSynthesis.speak(speech);
 }
btn.addEventListener("click",convertspeech);
