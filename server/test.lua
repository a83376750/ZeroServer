print("hello world")
print('lua hello')


function mafunction()
    print("ma function hello")

end


function readOnly(t)
    local proxy = { }
    local mt = {
        __index = t;
        __newindex = function(t, k, v)
            error("update a only table", 2);
        end
    }
    setmetatable(proxy, mt);
    return proxy;
end

--days = readOnly("1", "2");
--print(days[1]);
-- days[2] = "no";
