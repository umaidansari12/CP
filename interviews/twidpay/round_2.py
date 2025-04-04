# https://docs.google.com/document/d/1AEaJjJF3P86Z8pNrIdaQ_isBgbU_QyqYgzLoiCK3Q0s/edit
# keep track of transaction history
# maintain an expense map
# for each user it will output amount which he ows to the other person(x) 

# every time a transaction happened, basis on the type we will update transaction_map

# Input: u1 1000 4 u1 u2 u3 u4 EQUAL

# input : user_id paid_amount number_of_persons_involved [....] type

# transaction_map wil 

# expense_map = {user_id : [{lender_id, amount}], u1:[(l1, a1), (l2, a2)] , u2: [(l22,a22)]}

# just appending every transaction at each user_id in expense_map

# it should be at user level, like how much a user is owning to other users


class User:
    def __init__(self, id, name, email, mobile_number, total_balance):
      self.id = id
      self.name = name
      self.email = email
      self.mobile_number = mobile_number
      self.total_balance = total_balance
    
class ExpenseMap:
  def __init__(self):
    self.expense_map = {}
  def show(self, user_id):
    pass
  def balance_expenses(self):
    pass

class Transaction:
  def __init__(self, user_id, paid_amount, lender_ids, lender_ids_length, type, paid_amount_split=[]):
    self.user_id = user_id
    self.lender_ids = lender_ids
    self.lender_ids_length = lender_ids_length
    self.paid_amount = paid_amount
    self.type = type
    self.paid_amount_split = paid_amount_split

  def transact(self, expense_map_obj):
    if self.type == 'EQUAL':
      distributed_amount = self.paid_amount / self.lender_ids_length
      for user in self.lender_ids:
        if(user != self.user_id):
          # if self.user_id in expense_map_obj.expense_map:
            # expense_map_obj.expense_map[self.user_id].append((user, distributed_amount))
          # else:
            # expense_map_obj.expense_map[self.user_id] = [(user, distributed_amount)]
          if self.user_id in expense_map_obj.expense_map:
            if user in expense_map_obj.expense_map[self.user_id]:
              expense_map_obj.expense_map[self.user_id][user]+=distributed_amount
            else:
              expense_map_obj.expense_map[self.user_id][user]=distributed_amount
          else:
            expense_map_obj.expense_map[self.user_id][user] = distributed_amount
          if user in expense_map_obj.expense_map:
            expense_map_obj.expense_map[user][self.user_id]-=distributed_amount
          else:
            expense_map_obj.expense_map[user][self.user_id] = distributed_amount
    elif self.type == 'EXACT':
      for (user, amount) in zip(self.lender_ids, self.paid_amount_split):
        if self.user_id in expense_map_obj.expense_map:
          expense_map_obj.expense_map[self.user_id].append((user, amount))
        else:
          expense_map_obj.expense_map[self.user_id] = [(user, amount)]      
      

if __name__ == '__main__':
  u1 = User(1, "u1", "u1@example.com", "1234567894", 0)
  u2 = User(2, "u2", "u2@example.com", "1234567893", 0)
  u3 = User(3, "u3", "u3@example.com", "1234567892", 0)
  u4 = User(4, "u4", "u4@example.com", "1234567891", 0)
  e1 = ExpenseMap()
  t1 = Transaction(1,1000,[1,2,3,4], 4, 'EQUAL')
  print(e1.expense_map)
  t1.transact(e1)
  print(e1.expense_map)
  # t2 = Transaction(2, 1250, [1,3], 2, 'EXACT', [370, 880])
  # t2 = Transaction(1, 1250, [2,3], 2, 'EXACT', [370, 880])
  # t2.transact(e1)
  # print(e1.expense_map)
  
  
  


# u1 = {l1:amount}
# +ve means l1->u1
# -ve means u1->l1
# l1 = {u1:-amount}