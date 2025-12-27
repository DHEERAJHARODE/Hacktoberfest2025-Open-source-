try { 
	webengage.survey.onSubmit(function (data) {
    if (data.surveyId === "33l135e") {
        var email;
        var first_name;
        var phone_no;
        for (var i = 0; i < data.questionResponses.length; i++) {
            if (
                Object.prototype.toString.call(
                    data.questionResponses[i].value.values
                ) == "[object Object]"
            ) {
                console.log("object");
                for (var keys in data.questionResponses[i].value.values) {
                    if (keys == "Enter full name") {
                        first_name = data.questionResponses[i].value.values[keys];
                    }
                    if (keys == "Phone Number") {
                        phone_no = data.questionResponses[i].value.values[keys];
                    }
                  if (keys == "Email Address") {
                        email = data.questionResponses[i].value.values[keys];
                    }
                }
            }
        }
        console.log("we_first_name", first_name);
        console.log("we_phone", phone_no);
        console.log("we_email", email);
        if (
            webengage &&
            webengage.state &&
            typeof webengage.state.getForever === "function" &&
            (webengage.state.getForever().cuid === null ||
                webengage.state.getForever().cuid === undefined) &&
            email !== null
        )
        {
          webengage.user.login(email);
          webengage.track('Survey_Submit', {
                "we_first_name": first_name,
               "we_phone": phone_no,
              "we_email": email
            });
        }
    }
});
 } catch(e) { 
 	if (e instanceof Error) { 
		var data = e.stack || e.description;
		data = (data.length > 900 ? data.substring(0, 900) : data);
	 	webengage.eLog(null, 'error', data, 'cwc-error','cwc', '3k9e6i7');
	 }
 }
