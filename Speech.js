// Check if the browser supports the Speech Synthesis API
if ('speechSynthesis' in window) {
    const speechSynthesis = window.speechSynthesis;
    const speakButton = document.getElementById('speakButton');
    const textToSpeak = document.getElementById('textToSpeak');

    speakButton.addEventListener('click', function () {
        // Create a new SpeechSynthesisUtterance object
        const speech = new SpeechSynthesisUtterance();

        // Set the text to be spoken
        speech.text = textToSpeak.value;

        // You can set additional properties, such as voice, rate, pitch, etc.
        // speech.voice = ...;
        // speech.rate = ...;
        // speech.pitch = ...;

        // Speak the text
        speechSynthesis.speak(speech);
    });
} else {
    // Speech Synthesis API is not supported by the browser
    alert('Sorry, your browser does not support speech synthesis.');
}
