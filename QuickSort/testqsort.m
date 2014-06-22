function run()
clc
list = [4 7 5 3 9 1 4 6 3 5];
startpoint = 1;
endpoint   = length(list);
output = qsorting(list)

end

function output = qsorting(list)
startpoint = 1;
endpoint = length(list);
    if(startpoint >= endpoint)
        output = list;
    else
        flag = startpoint;
        for i = (startpoint+1):endpoint
            if(list(startpoint)>list(i))
                flag = flag+1;
                %swap
                temp = list(flag);
                list(flag) = list(i);
                list(i) = temp;
            end
        end
        %swap
        temp = list(startpoint);
        list(startpoint) = list(flag);
        list(flag) = temp;
        
        output = list;
        %recursive
        output(startpoint:flag) = qsorting(output(startpoint:flag));
        output(flag+1:endpoint) = qsorting(output(flag+1:endpoint));
    end
end