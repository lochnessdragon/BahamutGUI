-- downloads source code dependencies from something like github.

function addPackage(url) 
	if (string.startswith(url, 'gh'))
	then 
		--print("Github url detected!")
		str_prts = string.explode(url, ":")
		
		gh_repo = string.explode(str_prts[2], "/")
		--print("Github Repo Identified: " .. gh_repo[1] .. " Name: " .. gh_repo[2])
		
		io.write("Detecting if " .. str_prts[2] .. " is installed...")
		
		if (os.isdir(gh_repo[2]))
		then 
			print("Installed!")
		else 
			print("Not Installed.")
			
			os.execute("git clone https://github.com/" .. str_prts[2] ..".git")
		end
	else 
		print("No other package managing supported at this time")
	end
end