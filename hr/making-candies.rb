#!/bin/ruby

require 'json'
require 'stringio'

# Complete the minimumPasses function below.
def minimumPasses(m, w, p, n)
  #puts "[m,w,p,n]=#{[m,w,p,n]}"
  day = 0
  candies = 0
  scale = 1
  while candies < n
    # brand new day!
    day+=1
    # let's make some candies!
    candies += m*w
    #puts "day #{day}: made #{candies} of #{n}"
    break if candies >= n
    if candies < scale*p
      # fastforward until we can buy or done making candies
      tomake = [scale*p - candies, n - candies].min
      ff = (tomake/(1.0*m*w)).ceil
      day += ff
      candies += ff*m*w
      #puts "fastforward #{ff} days"
      #puts "day #{day}: made #{candies} of #{n}"
      break if candies >= n
    end
    # buying decision
    remaining_dontbuy = ((n-candies)/(1.0*m*w)).ceil
    # balance number of workers and machines
    buying_power = candies/p
    total_resource = m + w + buying_power
    if m - w > buying_power
      w_plus = w + buying_power
      m_plus = m
    elsif w - m > buying_power
      m_plus = m + buying_power
      w_plus = w
    else
      m_plus = total_resource/2
      w_plus = total_resource/2 + total_resource%2
    end
    candies_left = candies % p
    remaining_maxbuy = ((n-candies_left)/(1.0*m_plus*w_plus)).ceil
    # compare two options
    #puts "#{remaining_dontbuy} vs #{remaining_maxbuy}"
    if remaining_maxbuy <= remaining_dontbuy
      #puts "buying #{buying_power} => #{m_plus}m + #{w_plus}w"
      #puts "#{candies_left} = #{candies%p}"
      candies = candies_left
      w = w_plus
      m = m_plus
    else
      # fastforward to next bigger buying opportunity
      scale +=1
    end
  end
  return day
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

mwpn = gets.rstrip.split

m = mwpn[0].to_i

w = mwpn[1].to_i

p = mwpn[2].to_i

n = mwpn[3].to_i

result = minimumPasses m, w, p, n

fptr.write result
fptr.write "\n"

fptr.close()

