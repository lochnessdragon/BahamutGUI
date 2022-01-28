-- downloads source code dependencies from something like github.

local function downloadProgress(total, current)
  local ratio = current / total;
  ratio = math.min(math.max(ratio, 0), 1);
  local percent = math.floor(ratio * 100);
  print("Download progress (" .. percent .. "%/100%)")
end

function addPackage(url) 
	local parts = string.explode(url, ":")
	
	if (parts[1] == "gh") then 
		--print("Github url detected!")
		local gh_repo = string.explode(parts[2], "/")
		--print("Github Repo Identified: " .. gh_repo[1] .. " Name: " .. gh_repo[2])
		
		io.write("Detecting if " .. parts[2] .. " is installed...")
		
		if (os.isdir(gh_repo[2]))
		then 
			print("Installed!")
		else 
			print("Not Installed.")
			
			os.execute("git clone --recursive https://github.com/" .. parts[2] ..".git")
		end
	elseif (parts[1] == "zip") then
		local url_parts = string.explode(parts[2], "/")
		local filename = url_parts[#url_parts]
		local filenameNoExt = filename:sub(1, -5)
		-- detect if its already been downloaded
		if(os.isdir(filenameNoExt))
		then 
			print(filenameNoExt .. " is Installed!")
		else
			print("Installing: " .. filenameNoExt)

			-- if no, then download the zip 
			local result_str, response_code = http.download(("http://" .. parts[2]), (filename), {
    		progress = downloadProgress,
    		headers = { "From: Premake", "Referer: Premake" }
			})

			if(result_str == "OK")
			then
				-- unzip it
				zip.extract(filename, filenameNoExt)

				-- remove the zip file
				os.remove(filename)
			else 
				print("Failed to download: " .. parts[2])
				print("HTTP Code: " .. response_code)
				print("Description: " .. result_str)
			end
		end
	else 
		print("No other package managing supported at this time")
	end
end