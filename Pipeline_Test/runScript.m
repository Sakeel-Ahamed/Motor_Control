function runScript(inputText, extraArg)

    fprintf("Pipeline passed: %s\n", inputText);

    if ~exist('output','dir')
        mkdir('output');
    end

    fid = fopen(fullfile('output','result.txt'),'w');

    fprintf(fid,"Input from pipeline:\n");
    fprintf(fid,"%s\n",inputText);

    if strcmp(inputText, 'buildAll')
        fprintf(fid,"Version: %s\n", extraArg);
    else
        fprintf(fid,"Project: %s\n", extraArg);
    end

    fclose(fid);

    disp("Artifact created.");
end
