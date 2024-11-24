% Disease and corresponding symptoms as separate facts

% Flu symptoms
has_symptom(flu, fever).
has_symptom(flu, cough).
has_symptom(flu, fatigue).

% Cold symptoms
has_symptom(cold, cough).
has_symptom(cold, runny_nose).
has_symptom(cold, sneezing).
has_symptom(cold, sore_throat).

% COVID symptoms
has_symptom(covid, fever).
has_symptom(covid, cough).
has_symptom(covid, fatique).
has_symptom(covid, loss_of_taste).
has_symptom(covid, shortness_of_breath).

% Allergy symptoms
has_symptom(allergy, cough).
has_symptom(allergy, sneezing).
has_symptom(allergy, runny_nose).
has_symptom(allergy, itchy_eyes).

% Strep throat symptoms
has_symptom(strep_throat, sore_throat).
has_symptom(strep_throat, fever).
has_symptom(strep_throat, swollen_lymph_nodes).

% Rule to diagnose a disease based on a list of symptoms
diagnose(Disease, Symptoms) :-
    all_symptoms_match(Disease, Symptoms),      % Check if all symptoms match the disease
    format('Based on your symptoms ~w, you might have: ~w.~n', [Symptoms, Disease]).

% Rule to check if all symptoms match a disease
all_symptoms_match(_, []).                      % Base case: Empty list matches anything
all_symptoms_match(Disease, [H|T]) :-           % Recursively check each symptom
% write(Disease), write(' has symptom '), write(H), nl,  % Debugging line
    has_symptom(Disease, H),                    % Check if the disease has the current symptom
    all_symptoms_match(Disease, T).             % Check the rest of the symptoms