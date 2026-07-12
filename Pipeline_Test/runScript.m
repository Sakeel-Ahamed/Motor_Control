function runScript(inputText)

fprintf("Pipeline passed: %s\n", inputText);

if ~exist('output','dir')
    mkdir('output');
end

fid = fopen(fullfile('output','result.txt'),'w');

fprintf(fid,"Input from pipeline:\n");
fprintf(fid,"%s\n",inputText);

fclose(fid);

disp("Artifact created.");